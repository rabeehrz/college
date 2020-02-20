#! /bin/bash
echo -e "$(system_profiler SPSoftwareDataType)"
echo -e "\n---------------------------------------------- SHELLS -------------------------------------\n"
cat "/etc/shells" | grep "/bin"
echo -e "\n$(system_profiler SPHardwareDataType)"
echo -e "\n$(system_profiler SPMemoryDataType)"
echo -e "\n$(system_profiler SPStorageDataType)"
mount | column -t
