#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/module.h>
#include <linux/types.h>

/*Module info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_VERSION("1:3.0");
MODULE_DESCRIPTION("chardev_1 major/minor number allocation, static methord");


/* Creatig the major number and minor number*/
dev_t dev= MKDEV(135,1);
		
/* Module init */	
static int __init ext0_hello_module_init(void)
{
 printk (KERN_INFO "Hello World this is major/minor number example\r\n");
 if(register_chrdev_region(dev, 1, "Mahi")==NULL)
 {
	 printk (KERN_INFO "Major number= %d || Minor number= %d\r\n", MAJOR(dev), MINOR(dev));
 }
 else
 {
	 printk (KERN_ERR "Fail to regiter the major/mninor numbers!\r\n");
 }
 return 0;
}

/*Module exit*/

static void __exit ext0_hello_module_exit(void)
{
	printk(KERN_INFO "Goodbye World! unregitering the major/minor number\r\n");
	unregister_chrdev_region(dev, 1);
}

module_init(ext0_hello_module_init);
module_exit(ext0_hello_module_exit);

