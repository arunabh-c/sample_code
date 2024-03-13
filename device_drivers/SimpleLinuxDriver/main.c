#include "device_file.h"
#include <linux/init.h>       /* module_init, module_exit */
#include <linux/module.h>     /* version info, MODULE_LICENSE, MODULE_AUTHOR, printk() */

MODULE_DESCRIPTION("Simple Linux driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Apriorit, Inc");

/*===============================================================================================*/
//driver initialization entry point and is called during system startup (if the driver is statically 
//compiled into the kernel) or when the module is inserted into the kernel
static int simple_driver_init(void)
{
    int result = 0;
    printk( KERN_NOTICE "Simple-driver: Initialization started\n" );

    result = register_device();
    return result;
}

/*===============================================================================================*/
//unloading a module from the Linux kernel. This function has no effect if the driver is statically
//compiled into the kernel.
static void simple_driver_exit(void)
{
    printk( KERN_NOTICE "Simple-driver: Exiting\n" );
    unregister_device();
}

/*===============================================================================================*/
module_init(simple_driver_init);
module_exit(simple_driver_exit);
