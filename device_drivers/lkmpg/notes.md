> A **Linux kernel module** is precisely defined as a code segment capable of
dynamic loading and unloading within the kernel as needed. These modules
enhance kernel capabilities without necessitating a system reboot.

> To check for modules in kernel use `sudo lsmod` . to search for 'fat' use `sudo lsmod | greap fat`

> Modules stored withing **file /proc/modules** (`sudo cat /proc/modules`)

> **MODVERSIONING**: A module compiled for one kernel will not load if a different
kernel is booted, unless CONFIG_MODVERSIONS is enabled in the kernel.


```
int init_module(void)//called when the module is insmoded into the kernel
{
    pr_info("Hello world 1.\n");
    /* A non 0 return means init_module failed; will give an error message saying loading not permitted*/
    return 0;
}
//registers a handler for something with the
//kernel, or it replaces one of the kernel functions with its own code

void cleanup_module(void)//called just before it is removed from the kernel
{
    pr_info("Goodbye world 1.\n");//can be pr_debug for debug messages
}
```


> `modinfo hello-1.ko` to check if the source compiled into the .ko

> `sudo insmod hello-1.ko` to load the module

> `sudo lsmod | grep hello` should show the module

> `sudo rmmod hello_1` removes the module

> `sudo journalctl --since "1 hour ago" | grep kernel` shows the logs

> indentation within your code should be using tabs and not spaces

> Can give init and exit functions any name and instead call **module_init/exit** at the bottom e.g.


```
static int __init hello_2_init(void)
{..}//__init macro causes the init function to be discarded and its memory freed
//once the init function finishes for built-in drivers, but not loadable modules

static void __exit hello_2_exit(void)
{..}//__exit macro causes the omission of the function when the module
is built into the kernel, and like __init, has no effect for loadable modules

module_init(hello_2_init);

module_exit(hello_2_exit);
```

> There is also an ** __initdata** which works similarly to __init but for init
variables rather than functions. e.g. `static int hello3_data __initdata = 3;`

> To allow arguments to be passed to your module, declare the variables that
will take the values of the command line arguments as global and then use the
**module_param() macro** e.g.

```
static int myint = 420;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);//permissions bits
//for the corresponding file in sysfs
MODULE_PARM_DESC(myint, "An integer");

static int myintarray[2] = { 420, 420 };
static int arr_argc = 0;
module_param_array(myintarray, int, &arr_argc, 0000);
//arr_argc is pointer to the variable that will store the number of elements of the array
//initialized by the user at module loading time
MODULE_PARM_DESC(myintarray, "An array of integers");
```

to load the module, give command `sudo insmod hello-5.ko myint=5 myintarray=-1,-1`

good use for this is to have the module variable’s default values set, like
a port or IO address

> For modules spanning multiple files, put the following line in makefile:

`startstop-objs := start.o stop.o`

> **forced module unloading**
(MODULE_FORCE_UNLOAD): when this option is enabled, you can force the kernel
to unload a module even when it believes it is unsafe, via a sudo rmmod -f module
command

> version magic strings are stored in the module object in
the form of a static string, starting with `vermagic: 5.4.0-70-generic SMP mod_unload modversions`
that can be observed by the command `modinfo module.ko`

> to get list of all symbols exported by your kernel do `cat /proc/kallsyms`

> strace is a handy program that gives you details about what system calls a program
is making, including which call is made, what its arguments are and what it
returns.

> CPUs operate in different modes, each offering varying levels
of system control. The Intel 80386 architecture, for example, featured four such
modes, known as rings. Unix, however, utilizes only two of these rings: the
highest ring (ring 0, also known as “supervisor mode”, where all actions are
permissible) and the lowest ring, referred to as “user mode”.

> declare all your variables as static and to use a well-defined prefix for your
symbols to prevent variable names of different modules from crashing and also prevent namespace pollution

> Device Drivers
```
$ ls -l /dev/hda[1-3]
brw-rw---- 1 root disk 3, 1 Jul 5 2000 /dev/hda1 //3 is major number
brw-rw---- 1 root disk 3, 2 Jul 5 2000 /dev/hda2 //2 is minor number
brw-rw---- 1 root disk 3, 3 Jul 5 2000 /dev/hda3 //first letter b means block device
```
> Difference between Block & Char devices:
1. block devices have a buffer for requests, so they can choose
the best order in which to respond to the requests. This is important in the
case of storage devices, where it is faster to read or write sectors which are close
to each other, rather than those which are further apart.
2. block devices can only accept input and return output in blocks (whose size
can vary according to the device), whereas character devices are allowed to use
as many or as few bytes as they like

> To create a new char device named coffee with major/minor
number 12 and 2, simply do `mknod /dev/coffee c 12 2`//device files, located
in /dev.

> file_operations structure is defined in include/linux/fs.h, and holds
pointers to functions defined by the driver that perform various operations on
the device. Each field of the structure corresponds to the address of some function
defined by the driver to handle a requested operation. Syntax:
```
struct file_operations fops = {
 .read = device_read,
 .write = device_write,
 .open = device_open,
 .release = device_release//any member of the
 //structure which you do not explicitly assign will be initialized to NULL by gcc
};
```

> the read, write and seek operations are guaranteed for
thread-safe by using the f_pos specific lock, which makes the file position update
to become the mutual exclusion

> since Linux v5.6, the proc_ops structure was introduced to replace
the use of the file_operations structure when registering proc handlers.

> **File Structure of device drivers**: Each device is represented in the kernel by a file structure.
a file is a kernel level structure and never
appears in a user space program. It is not the same thing as a FILE, which is
defined by glibc and would never appear in a kernel space function. Also, its
name is a bit misleading; it represents an abstract open ‘file’, not a file on a
disk, which is represented by a structure named inode. An instance of struct file is
commonly named filp. You’ll also see it referred to as a struct file object

> **Registering char dd**:
```
int register_chrdev(unsigned int major, const char *name,
struct file_operations *fops);
```

> Better way to register to redue waste for char device registration is using cdev interface.
```
int register_chrdev_region(dev_t from, unsigned count, const char *name);\\if major num known
int alloc_chrdev_region(dev_t *dev, unsigned baseminor, unsigned count, const char *name);\\dynamically alloc major
//struct cdev *my_dev = cdev_alloc();//initialize the data structure struct cdev for our char device and associate 
//my_cdev->ops = &my_fops;//it with the device numbers
void cdev_init(struct cdev *cdev, const struct file_operations *fops);//common usage pattern
int cdev_add(struct cdev *p, dev_t dev, unsigned count);
```
