import os
import random
from scapy.all import ARP, Ether, srp

def scan_network(ip_range):
    # Create ARP request packet
    arp = ARP(pdst=ip_range)
    # Create Ethernet frame
    ether = Ether(dst="ff:ff:ff:ff:ff:ff")
    # Stack them together
    packet = ether/arp
    
    # Send the packet and receive the response
    result = srp(packet, timeout=3, verbose=0)[0]
    
    # List of discovered devices
    devices = []
    
    for sent, received in result:
        devices.append({'ip': received.psrc, 'mac': received.hwsrc})
    
    return devices

def change_mac(interface, new_mac):
    print(f"[+] Changing MAC address for {interface} to {new_mac}")
    # Disable the network interface
    os.system(f"ifconfig {interface} down")
    # Change the MAC address
    os.system(f"ifconfig {interface} hw ether {new_mac}")
    # Enable the network interface
    os.system(f"ifconfig {interface} up")

def main():
    ip_range = "192.168.1.0/24"  # Adjust according to your network
    devices = scan_network(ip_range)
    
    if not devices:
        print("No devices found.")
        return
    
    # Randomly select a MAC address from the discovered devices
    random_device = random.choice(devices)
    random_mac = random_device['mac']
    
    # Specify your network interface (e.g., eth0, wlan0)
    interface = "eth0"  # Change this to your network interface
    
    change_mac(interface, random_mac)
    print(f"New MAC address set: {random_mac}")

if __name__ == "__main__":
    main()
