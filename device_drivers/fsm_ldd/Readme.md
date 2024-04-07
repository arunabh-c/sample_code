> 3 files shown from easy to complex

> to compile c files into .ko files, give command sudo make -C /usr/src/kernels/5.15.145-95.161.amzn2.x86_64 M=`pwd` modules

> to add the module to the kernel, give the following command (e.g. memory.c): sudo insmod memory.ko

>  Check for the drive loaded by giving command lsmod

> Driver Init Message can be tallied by giving command sudo dmesg

> To remove driver, give command sudo rmmod memory
>
> Reference: http://freesoftwaremagazine.com/articles/drivers_linux/
