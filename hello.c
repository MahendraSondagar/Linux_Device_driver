#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/*Module info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_DESCRIPTION("First hello world module");
MODULE_VERSION("1:3.0");

/* module init */

static int __init ext0_hello_module_init(void)
{
	printk (KERN_INFO "Hello world\r\n");
	return 0;
}

/*module exit  **/
static void __exit ext0_hello_module_exit(void)
{
	printk (KERN_INFO "Goodbye world\r\n");
}


module_init(ext0_hello_module_init);
module_exit(ext0_hello_module_exit);

