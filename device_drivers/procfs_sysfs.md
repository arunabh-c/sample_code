**Procfs**:

On the root, there is a folder titled “proc”. This folder is not really on /dev/sda1 or where ever you think the folder resides. 
This folder is a mount point for the procfs (Process Filesystem) which is a filesystem in memory. Many processes store information
about themselves on this virtual filesystem. ProcFS also stores other system information.

It can act as a bridge connecting the user space and the kernel space. Userspace programs can use proc files to read the information 
exported by the kernel. Every entry in the proc file system provides some information from the kernel.

The entry “meminfo”  gives the details of the memory being used in the system.
To read the data in this entry just run

```
cat /proc/meminfo
```
Similarly the “modules” entry gives details of all the modules that are currently a part of the kernel.

```
cat /proc/modules
```

Most proc files are read-only and only expose kernel information to user space programs.

proc files can also be used to control and modify kernel behavior on the fly. The proc files need to be writable in this case.

The proc entry can also be used to pass data to the kernel by writing into the kernel, so there can be two kinds of proc entries.

1. An entry that only reads data from the kernel space.

2. An entry that reads as well as writes data into and from kernel space.
