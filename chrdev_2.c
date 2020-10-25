#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/types.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_VERSION("1:3.0");
MODULE_DESCRIPTION("chardev major/minor number registration dynamic methord");

/* Creating the instance to hold the numbers*/
dev_t dev=0;

/*Module init */
static int __init ext0_hello_module_init(void)
{
	printk (KERN_INFO "Hello world\r\n");
	/* Dynamically registering the numbers */
	if(alloc_chrdev_region(&dev, 0,1, "MahiDev")==0)
	{
		printk ("Major number = %d || Minor number= %d\r\n", MAJOR(dev), MINOR(dev));
	}
	else
	{
		printk(KERN_ERR "Fail to register the Major/Minor number!\r\n");
	}


	return 0;
}

/*Module exit  */
static void __exit ext0_hello_module_exit(void)
{
	printk (KERN_INFO "GoodBye World!\r\n");
	unregister_chrdev_region(dev, 1);
}

module_init(ext0_hello_module_init);
module_exit(ext0_hello_module_exit);
