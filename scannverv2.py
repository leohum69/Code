from scapy.all import *
import os
import sys
import time

# --- Helper: Check for root privileges ---
def check_root():
    if os.geteuid() != 0:
        print("This script requires root privileges. Please run with sudo.")
        sys.exit(1)

# --- Host Discovery Scans ---

def host_discovery_icmp(target):
    pkt = IP(dst=target)/ICMP()
    ans, _ = sr(pkt, timeout=2, verbose=0)
    for snd, rcv in ans:
        print(f"[+] Host {rcv.src} is up (ICMP Ping)")

def host_discovery_tcp_ack(target):
    pkt = IP(dst=target)/TCP(dport=80, flags="A")
    ans, _ = sr(pkt, timeout=2, verbose=0)
    for snd, rcv in ans:
        if rcv.haslayer(TCP) and rcv[TCP].flags == "R":
            print(f"[+] Host {rcv.src} is up (TCP ACK Ping)")

def host_discovery_sctp_init(target, port=3868):
    try:
        # SCTP support is in the contrib module.
        from scapy.contrib.sctp import SCTP, SCTPChunkInit
    except ImportError:
        print("SCTP support not available in Scapy.")
        return
    pkt = IP(dst=target)/SCTP(dport=port)/SCTPChunkInit()
    response = sr1(pkt, timeout=2, verbose=0)
    if response:
        print(f"[+] Host {target} is up (SCTP INIT Ping) - Response received")
    else:
        print(f"[-] No response from {target} on SCTP port {port}")

def host_discovery_icmp_timestamp(target):
    # ICMP Timestamp Request is type=13; reply is type=14.
    pkt = IP(dst=target)/ICMP(type=13)
    response = sr1(pkt, timeout=2, verbose=0)
    if response and response.haslayer(ICMP) and response.getlayer(ICMP).type == 14:
        # ts_recv is the received timestamp (if available)
        ts = getattr(response.getlayer(ICMP), "ts_recv", "N/A")
        print(f"[+] Host {target} is up (ICMP Timestamp Ping) - Received timestamp: {ts}")
    else:
        print(f"[-] No valid response from {target} for ICMP Timestamp Ping")

def host_discovery_icmp_addrmask(target):
    # ICMP Address Mask Request (type=17) and Reply (type=18)
    pkt = IP(dst=target)/ICMP(type=17)
    response = sr1(pkt, timeout=2, verbose=0)
    if response and response.haslayer(ICMP) and response.getlayer(ICMP).type == 18:
        mask = getattr(response.getlayer(ICMP), "addr_mask", "Unknown")
        print(f"[+] Host {target} is up (ICMP Address Mask Ping) - Address Mask: {mask}")
    else:
        print(f"[-] No valid response from {target} for ICMP Address Mask Ping")

def host_discovery_arp(target):
    pkt = Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst=target)
    ans, _ = srp(pkt, timeout=2, verbose=0)
    for snd, rcv in ans:
        print(f"[+] Host {rcv[ARP].psrc} is up (ARP Ping) - MAC: {rcv[Ether].src}")

# --- OS Detection ---

def os_detection_ttl(target):
    pkt = IP(dst=target)/ICMP()
    response = sr1(pkt, timeout=2, verbose=0)
    if response:
        ttl = response.ttl
        if ttl <= 64:
            os_guess = "Linux/Unix"
        elif ttl <= 128:
            os_guess = "Windows"
        else:
            os_guess = "Unknown"
        print(f"[+] {target} TTL: {ttl} - Possible OS: {os_guess}")
    else:
        print(f"[-] No response from {target}")

# --- Port Scanning Functions ---

def port_scan_tcp_connect(target, ports):
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="S"), timeout=1, verbose=0)
        if pkt and pkt.haslayer(TCP) and pkt[TCP].flags == "SA":
            # Send RST to close connection
            send(IP(dst=target)/TCP(dport=port, flags="R"), verbose=0)
            print(f"[+] TCP {port} - Open")
        elif pkt and pkt.haslayer(TCP) and pkt[TCP].flags in ["RA", "R"]:
            print(f"[-] TCP {port} - Closed")
        else:
            print(f"[?] TCP {port} - Filtered")

def port_scan_udp(target, ports):
    for port in ports:
        pkt = sr1(IP(dst=target)/UDP(dport=port), timeout=2, verbose=0)
        if pkt is None:
            print(f"[+] UDP {port} - Open|Filtered")
        elif pkt.haslayer(ICMP):
            if pkt[ICMP].type == 3 and pkt[ICMP].code == 3:
                print(f"[-] UDP {port} - Closed")
            else:
                print(f"[?] UDP {port} - ICMP type {pkt[ICMP].type} code {pkt[ICMP].code}")

def port_scan_tcp_null(target, ports):
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags=""), timeout=1, verbose=0)
        if pkt is None:
            print(f"[+] TCP {port} (NULL Scan) - Open|Filtered")
        elif pkt.haslayer(TCP) and pkt[TCP].flags == "R":
            print(f"[-] TCP {port} (NULL Scan) - Closed")
        else:
            print(f"[?] TCP {port} (NULL Scan) - Unexpected response")

def port_scan_tcp_fin(target, ports):
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="F"), timeout=1, verbose=0)
        if pkt is None:
            print(f"[+] TCP {port} (FIN Scan) - Open|Filtered")
        elif pkt.haslayer(TCP) and pkt[TCP].flags == "R":
            print(f"[-] TCP {port} (FIN Scan) - Closed")
        else:
            print(f"[?] TCP {port} (FIN Scan) - Unexpected response")

def port_scan_tcp_xmas(target, ports):
    # Xmas scan sets FIN, PSH, and URG flags.
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="FPU"), timeout=1, verbose=0)
        if pkt is None:
            print(f"[+] TCP {port} (Xmas Scan) - Open|Filtered")
        elif pkt.haslayer(TCP) and pkt[TCP].flags == "R":
            print(f"[-] TCP {port} (Xmas Scan) - Closed")
        else:
            print(f"[?] TCP {port} (Xmas Scan) - Unexpected response")

def port_scan_tcp_ack_scan(target, ports):
    # TCP ACK scan helps determine if ports are filtered.
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="A"), timeout=1, verbose=0)
        if pkt is None:
            print(f"[?] TCP {port} (ACK Scan) - Filtered")
        elif pkt.haslayer(TCP) and pkt[TCP].flags == "R":
            print(f"[+] TCP {port} (ACK Scan) - Unfiltered")
        else:
            print(f"[?] TCP {port} (ACK Scan) - Unexpected response")

def port_scan_tcp_window(target, ports):
    # TCP Window scan: analyze the window size in RST responses.
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="A"), timeout=1, verbose=0)
        if pkt is None:
            print(f"[?] TCP {port} (Window Scan) - Filtered or no response")
        elif pkt.haslayer(TCP):
            window = pkt[TCP].window
            # Note: This is a heuristic; window values can vary by OS.
            if window == 0:
                print(f"[+] TCP {port} (Window Scan) - Open (window=0)")
            else:
                print(f"[-] TCP {port} (Window Scan) - Closed (window={window})")
        else:
            print(f"[?] TCP {port} (Window Scan) - Unexpected response")

def port_scan_tcp_maimon(target, ports):
    # TCP Maimon scan: send a FIN scan with an unusual ACK value.
    for port in ports:
        pkt = sr1(IP(dst=target)/TCP(dport=port, flags="F", seq=1000, ack=1), timeout=1, verbose=0)
        if pkt is None:
            print(f"[+] TCP {port} (Maimon Scan) - Open|Filtered")
        elif pkt.haslayer(TCP) and pkt[TCP].flags == "R":
            print(f"[-] TCP {port} (Maimon Scan) - Closed")
        else:
            print(f"[?] TCP {port} (Maimon Scan) - Unexpected response")

def ip_protocol_scan(target, protocols):
    # For each protocol number, send an IP packet with that protocol field.
    for proto in protocols:
        pkt = sr1(IP(dst=target, proto=proto)/Raw(load=""), timeout=1, verbose=0)
        if pkt is None:
            print(f"[?] IP Protocol {proto} - No response (Open|Filtered)")
        elif pkt.haslayer(ICMP):
            icmp_type = pkt[ICMP].type
            icmp_code = pkt[ICMP].code
            if icmp_type == 3 and icmp_code == 2:
                print(f"[-] IP Protocol {proto} - Unreachable (closed)")
            else:
                print(f"[!] IP Protocol {proto} - ICMP type {icmp_type} code {icmp_code}")
        else:
            print(f"[+] IP Protocol {proto} - Open")

# --- Main Menu and Main ---

def main_menu():
    print("Network Scanning Tool")
    print("Host Discovery:")
    print("1. ICMP Ping")
    print("2. TCP ACK Ping")
    print("3. SCTP Init Ping")
    print("4. ICMP Timestamp Ping")
    print("5. ICMP Address Mask Ping")
    print("6. ARP Ping")
    print("7. Find MAC Address")
    print("\nOS Discovery:")
    print("8. OS Detection (TTL)")
    print("\nPort Scanning:")
    print("9. TCP Connect Scan")
    print("10. UDP Scan")
    print("11. TCP Null Scan")
    print("12. TCP FIN Scan")
    print("13. Xmas Scan")
    print("14. TCP ACK Scan")
    print("15. TCP Window Scan")
    print("16. TCP Maimon Scan")
    print("17. IP Protocol Scan")
    choice = input("Select scan type (1-17): ")
    target = input("Enter target IP/range: ")
    return choice, target

def main():
    check_root()
    # Define common ports for TCP/UDP scans.
    common_ports = [21, 22, 23, 25, 53, 80, 443, 3306, 3389]
    # Define some common IP protocols (ICMP=1, TCP=6, UDP=17, GRE=47, ESP=50, AH=51)
    common_protocols = [1, 6, 17, 47, 50, 51]
    
    choice, target = main_menu()
    
    if choice == "1":
        host_discovery_icmp(target)
    elif choice == "2":
        host_discovery_tcp_ack(target)
    elif choice == "3":
        host_discovery_sctp_init(target)
    elif choice == "4":
        host_discovery_icmp_timestamp(target)
    elif choice == "5":
        host_discovery_icmp_addrmask(target)
    elif choice == "6" or choice == "7":
        # Both options use ARP to discover hosts / MAC addresses.
        host_discovery_arp(target)
    elif choice == "8":
        os_detection_ttl(target)
    elif choice == "9":
        port_scan_tcp_connect(target, common_ports)
    elif choice == "10":
        port_scan_udp(target, common_ports)
    elif choice == "11":
        port_scan_tcp_null(target, common_ports)
    elif choice == "12":
        port_scan_tcp_fin(target, common_ports)
    elif choice == "13":
        port_scan_tcp_xmas(target, common_ports)
    elif choice == "14":
        port_scan_tcp_ack_scan(target, common_ports)
    elif choice == "15":
        port_scan_tcp_window(target, common_ports)
    elif choice == "16":
        port_scan_tcp_maimon(target, common_ports)
    elif choice == "17":
        ip_protocol_scan(target, common_protocols)
    else:
        print("Selected scan type not implemented in this example.")

if __name__ == "__main__":
    main()
