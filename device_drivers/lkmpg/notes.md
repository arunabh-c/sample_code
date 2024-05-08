> A **Linux kernel module** is precisely defined as a code segment capable of
dynamic loading and unloading within the kernel as needed. These modules
enhance kernel capabilities without necessitating a system reboot.

> To check for modules in kernel use `sudo lsmod` . to search for 'fat' use `sudo lsmod | greap fat`

> Modules stored within **file /proc/modules** (`sudo cat /proc/modules`)

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
> **Unregistering dd**:
rmmod of dd by kernel module is dangerous. There is a counter which keeps track of # of
processes using a certain module: `cat /proc/modules or sudo lsmod` and looking at 3rd field.
this amount is checked by `sys_delete_module` within `cleanup_module`. amount value can be incremented/decremented
and if value wrong then reboot.

> dump device file via `cat /proc/devices`

> concurrent access to the same memory may lead to the race condition, and will not preserve
the performance. In the kernel module, this problem may happen due
to multiple instances accessing the shared resources. Therefore, a solution is
to enforce the exclusive access. We use atomic **Compare-And-Swap (CAS)** to
maintain the states, **CDEV_NOT_USED** and **CDEV_EXCLUSIVE_OPEN**, to determine
whether the file is currently opened by someone or not. CAS compares the
contents of a memory location with the expected value and, only if they are the
same, modifies the contents of that memory location to the desired value

> to have kernel run across various kernel versions do the following:
```
#if LINUX_VERSION_CODE >= KERNEL_VERSION(6, 4, 0)
   cls = class_create(DEVICE_NAME);
#else
   cls = class_create(THIS_MODULE, DEVICE_NAME);
#endif
```
>  **/proc file system**
used by every bit of the kernel which has something interesting to report, such
as /proc/modules which provides the list of modules and /proc/meminfo which
gathers memory usage statistics. To use it, a structure is created with all
the information needed for the /proc file, including pointers to any handler
functions (in our case there is only one, the one called when somebody attempts
to read from the /proc file). Then, init_module registers the structure with
the kernel and cleanup_module unregisters it.

> the index-node (inode for short) number is a pointer to a disk location where
the /proc file’s inode is located. The inode contains information about the file, 
for example the file’s permissions, together with a pointer to the disk location 
or locations where the file’s data can be found.

> /proc/helloworld is created when the module is loaded with the function
`our_proc_file = proc_create(procfs_name, 0644, NULL, &proc_file_fops);`.
The return value is a pointer to struct proc_dir_entry, and it will be
used to configure the file /proc/helloworld.

> `static ssize_t procfile_read(struct file *file_pointer, char __user *buffer,
20 size_t buffer_length, loff_t *offset)` The content of the buffer will
be returned to the application which read it (for example the cat command).
The offset is the current position in the file. If the return value of the function
is not null, then this function is called again

> In Linux, there is a standard mechanism for file system registration. Since
every file system has to have its own functions to **handle inode and file operations**,
there is a special structure to hold pointers to all those functions,
**struct inode_operations**, which includes **a pointer to struct proc_ops**.
The difference between file and inode operations is that **file operations deal
with the file itself whereas inode operations deal with ways of referencing the
file, such as creating links to it**.

> 
```
#ifdef HAVE_PROC_OPS
static struct proc_ops file_ops_4_our_proc_file = {
    .proc_read = procfs_read,
    .proc_write = procfs_write,
    .proc_open = procfs_open,
    .proc_release = procfs_close,
};
```
> Read functions are used for output, whereas write functions are
used for input. The reason for that is that read and write refer to the user’s
point of view — if a process reads something from the kernel, then the kernel
needs to output it, and if a process writes something to the kernel, then the
kernel receives it as input.
```
static ssize_t procfs_read(struct file *filp, char __user *buffer,
                           size_t length, loff_t *offset)
static ssize_t procfs_write(struct file *file, const char __user *buffer,
                            size_t len, loff_t *off)
```
> there is an API named **seq_file** that helps formatting a
/proc file for output. It is based on sequence, which is composed of 3 functions:
**start(), next(), and stop()**. The seq_file API starts a sequence when a
user read the /proc file.
```
static struct seq_operations my_seq_ops = {
    .start = my_seq_start,
    .next = my_seq_next,
    .stop = my_seq_stop,
    .show = my_seq_show,
};
static void *my_seq_start(struct seq_file *s, loff_t *pos)
static void *my_seq_next(struct seq_file *s, void *v, loff_t *pos)
static void my_seq_stop(struct seq_file *s, void *v)
static int my_seq_show(struct seq_file *s, void *v)
```

> sysfs allows you to interact with the running kernel from userspace by reading or
setting variables inside of modules. This can be useful for debugging purposes,
or just as an interface for applications or scripts. You can find sysfs directories
and files under the /sys directory on your system.
`ls -l /sys`. Attributes can be exported for kobjects in the form of regular files in the
filesystem. Sysfs forwards file I/O operations to methods defined for the attributes,
providing a means to read and write kernel attributes.
```
static ssize_t myvariable_show(struct kobject *kobj,
                               struct kobj_attribute *attr, char *buf)
static ssize_t myvariable_store(struct kobject *kobj,
                                struct kobj_attribute *attr, char *buf,
                                size_t count)
static struct kobj_attribute myvariable_attribute =
    __ATTR(myvariable, 0660, myvariable_show, (void *)myvariable_store);
```
What is the current value of myvariable ?
`cat /sys/kernel/mymodule/myvariable`

Set the value of myvariable and check that it changed.
`echo "32" > /sys/kernel/mymodule/myvariable`

> **ioctl (short for Input Output ConTroL)** Every device can have
its own ioctl commands, which can be read ioctl’s (to send
information from a process to the kernel), write ioctl’s (to return
information to a process), both or neither. Notice here the roles of 
read and write are reversed again, so in ioctl’s read is to send information to
the kernel and write is to receive information from the kernel.
The ioctl function is called with **three parameters**: **the file descriptor** of the
appropriate device file, **the ioctl number**, and a **parameter, which is of type long**
so you can use a cast to use it to pass anything.

>
```
static long test_ioctl_ioctl(struct file *filp, unsigned int cmd,
38 unsigned long arg)

static ssize_t test_ioctl_read(struct file *filp, char __user *buf,
89 size_t count, loff_t *f_pos)

static int test_ioctl_close(struct inode *inode, struct file *filp)

static int test_ioctl_open(struct inode *inode, struct file *filp)

static struct file_operations fops = {
    .open = test_ioctl_open,
    .release = test_ioctl_close,
    .read = test_ioctl_read,
    .unlocked_ioctl = test_ioctl_ioctl,
};

```

> The ioctl number encodes the major device number,
the type of the ioctl, the command, and the type of the parameter. This ioctl
number is usually created by a macro call (_IO, _IOR, _IOW or _IOWR — depending
on the type) in a header file. This header file should then be included both by
the programs which will use ioctl (so they can generate the appropriate ioctl’s)
and by the kernel module (so it can understand it)
