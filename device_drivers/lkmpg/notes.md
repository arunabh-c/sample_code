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

static int myint = 420;
module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");
