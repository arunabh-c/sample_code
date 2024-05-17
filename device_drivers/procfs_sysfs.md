**Procfs**:

On the root, there is a folder titled “proc”. This folder is not really on /dev/sda1. 
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

**Sysfs**:

The files in Sysfs contain information about devices and drivers. Some files in Sysfs are even writable, for configuration and control of devices attached to the system. Sysfs is always mounted on /sys.

The directories in Sysfs contain the hierarchy of devices, as they are attached to the computer.

Sysfs is the commonly used method to export system information from the kernel space to the user space for specific devices. The SysFS is tied to the device driver model of the kernel.

**Kernel Objects**
The heart of the sysfs model is the kernel object. Kobject is the glue that binds the sysfs and the kernel, which is represented by struct kobject and defined in <linux/kobject.h>. 
A struct kobject represents a kernel object, maybe a device or so, such as the things that show up as a directory in the sysfs filesystem.

```
ls -l /sys/kernel
```

Reference: https://embetronicx.com/tutorials/linux/device-drivers/sysfs-in-linux-kernel/

**Configfs**:

configfs is a ram-based filesystem that provides the converse of
sysfs's functionality.  Where sysfs is a filesystem-based view of
kernel objects, configfs is a filesystem-based manager of kernel
objects, or config_items.

With sysfs, an object is created in kernel (for example, when a device
is discovered) and it is registered with sysfs.  Its attributes then
appear in sysfs, allowing userspace to read the attributes via
readdir(3)/read(2).  It may allow some attributes to be modified via
write(2).  **The important point is that the object is created and
destroyed in kernel, the kernel controls the lifecycle of the sysfs
representation, and sysfs is merely a window on all this.**

**A configfs config_item is created via an explicit userspace operation:
mkdir(2).**  It is destroyed via rmdir(2).  The attributes appear at
mkdir(2) time, and can be read or modified via read(2) and write(2).
As with sysfs, readdir(3) queries the list of items and/or attributes.
symlink(2) can be used to group items together.  **Unlike sysfs, the
lifetime of the representation is completely driven by userspace.**  The
kernel modules backing the items must respond to this.

Reference: https://www.kernel.org/doc/Documentation/filesystems/configfs/configfs.txt
