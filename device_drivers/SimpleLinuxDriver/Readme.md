Steps to run:
1. Navigate to the folder SimpleLinuxDriver
2. Give command `make load`
3. Check /proc/modules file and /proc/devices file to see `Simple-driver` loaded from Step 2.
4. Get major device number xxx from the /proc/devices file. It is < 255.
5. Give command `mknod /dev/simple-driver c  xxx 0` where xxx is the major device number
6. Give command `cat /dev/simple-driver` to make sure device works correctly.

Reference: https://www.apriorit.com/dev-blog/195-simple-driver-for-linux-os

https://www.tecmint.com/mknod-command/