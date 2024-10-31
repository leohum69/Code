import subprocess
import os
from flask import Flask, render_template, redirect, url_for

app = Flask(__name__)

def run_command(command):
    try:
        os.system(command)
    except subprocess.CalledProcessError as e:
        print(e.output)

@app.route('/')
def index():
    # Check current status
    status_command = 'reg query HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} >nul 2>&1'
    result = subprocess.call(status_command, shell=True)
    if result == 0:
        status = "ENABLED"
    else:
        status = "DISABLED"
    return render_template('index.html', status=status)

@app.route('/enable')
def enable():
    enable_commands = [
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\{53f5630d-b6bf-11d0-94f2-00a0c91efb8b} /v Deny_Write /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\{53f56307-b6bf-11d0-94f2-00a0c91efb8b} /v Deny_Write /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom\\Deny_Write /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom\\Deny_Write /v Deny_Write /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom\\Deny_Write\\List /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom\\Deny_Write\\List /v "{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}" /d "{53f5630d-b6bf-11d0-94f2-00a0c91efb8b}" /f',
        'reg add HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices\\Custom\\Deny_Write\\List /v "{53f56307-b6bf-11d0-94f2-00a0c91efb8b}" /d "{53f56307-b6bf-11d0-94f2-00a0c91efb8b}" /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorageDevicePolicies /v WriteProtect /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP /v DenyAllGPState /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /v EnumerateDevices /t REG_DWORD /d 1 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /v AccessBitMask /t REG_DWORD /d 0 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /v UserPolicy /t REG_DWORD /d 0 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /v AuditPolicyOnly /t REG_DWORD /d 0 /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /v SecurityDescriptor /t REG_SZ /d "D:(D;;DCLCRPCRSD;;;IU)(A;;FA;;;SY)(A;;FA;;;LS)(A;;0x1200a9;;;IU)" /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage /v HotplugSecurityDescriptor /t REG_BINARY /d "01000480000000000000000000000000140000000200580004000000010014001601010001010000000000050400000000001400ff011f0001010000000000051200000000001400ff011f0001010000000000051300000000001400a90012000101000000000005040>" /f'
    ]
    for cmd in enable_commands:
        run_command(cmd)
    
    subprocess.run(["gpupdate", "/force"], shell=True)

    subprocess.run("taskkill /f /im explorer.exe", shell=True)
    subprocess.run("start explorer.exe", shell=True)

    return redirect(url_for('index'))

@app.route('/disable')
def disable():
    disable_commands = [
        'reg delete HKLM\\SOFTWARE\\Policies\\Microsoft\\Windows\\RemovableStorageDevices /f',
        'reg delete HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage\\EnabledDenyGP\\{53F5630D-B6BF-11D0-94F2-00A0C91EFB8B} /f',
        'reg add HKLM\\SYSTEM\\CurrentControlSet\\Control\\StorageDevicePolicies /v WriteProtect /t REG_DWORD /d 0 /f',
        'reg delete HKLM\\SYSTEM\\CurrentControlSet\\Control\\Storage /v HotplugSecurityDescriptor /f'
    ]
    for cmd in disable_commands:
        run_command(cmd)

    subprocess.run(["gpupdate", "/force"], shell=True)

    subprocess.run("taskkill /f /im explorer.exe", shell=True)
    subprocess.run("start explorer.exe", shell=True)

    return redirect(url_for('index'))

@app.route('/quit')
def quit():
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
