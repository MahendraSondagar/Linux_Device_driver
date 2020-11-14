#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/types.h>


/* Module info
 * */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_VERSION("1:3.0");
MODULE_DESCRIPTION("Linux device file examsple");


dev_t dev=0;
/* Module init*/

static int __init ext0_hello_module_init(void)
{
	printk(KERN_INFO "Hello world \r\n");
	if(alloc_chrdev_region(&dev, 0,1, "Mahi_dev")==0)
	{
		printk (KERN_INFO "Major Number : %d || Minor number: %d\r\n", MAJOR(dev), MINOR (dev));
	}
	else
	{
	  printk(KERN_ALERT "Fail to register the Major/Minro number\r\n");
	}


	return 0;
}

/*Module exit */

static void __exit ext0_hello_module_exit(void)
{
	printk (KERN_INFO  "GoodBye world\r\n");
	unregister_chrdev_region(dev, 1);
}

module_init(ext0_hello_module_init);
module_exit(ext0_hello_module_exit);


