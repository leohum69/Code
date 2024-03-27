#!/bin/bash

CPU_THS=30
DISK_THS=30
MEM_THS=10
FILE_THS=10485760

echo "$(date +'%Y-%m-%d %H:%M:%S')" >> "log_file.log"

# echo $(top -bn1 | grep "Cpu(s)" | awk '{print $2}')

cpu_usage=$(top -bn1 | grep "Cpu(s)" | awk '{print $2}' | cut -d '.' -f1)
if [ "$cpu_usage" -gt "$CPU_THS" ]; then
    echo "CPU usage alert: $cpu_usage% used (threshold: $CPU_THS%)" >> "log_file.log"
fi

freemem=$(free | awk '/^Mem:/{print $4}')
totmem=$(free | awk '/^Mem:/{print $2}')
mem_usage=$((($totmem - $freemem) * 100 / $totmem))

# echo $mem_usage
# echo $totmem
# echo $freemem


if [ "$mem_usage" -gt "$MEM_THS" ]; then
    echo "Memory usage alert: $mem_usage% used (threshold: $MEM_THS%)" >> "log_file.log"
fi

# echo $(df -h | awk 'NR==2 {print $5}' | sed 's/%//')

disk_usage=$(df -h | awk 'NR==2 {print $5}' | sed 's/%//')
if [ "$disk_usage" -gt "$DISK_THS" ]; then
    echo "Disk usage alert: $disk_usage% used (threshold: $DISK_THS%)" >> "log_file.log"
fi


log_size=$(stat -c "%s" "log_file.log")
# echo $log_size

if [ "$log_size" -gt "$FILE_THS" ]; then
    echo "Log size alert: $log_size% used (threshold: $FILE_THS%)" >> "log_file.log"
fi