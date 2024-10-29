import subprocess
import re

def get_mac_addresses():
    # Run the 'ip link show' command
    result = subprocess.run(['ip', 'link', 'show'], capture_output=True, text=True)
    
    # Use regex to find all MAC addresses in the output
    mac_addresses = re.findall(r'link/ether ([0-9a-fA-F:]{17})', result.stdout)
    
    return mac_addresses

# Get and print all MAC addresses
mac_addresses = get_mac_addresses()
for mac in mac_addresses:
    print(mac)
