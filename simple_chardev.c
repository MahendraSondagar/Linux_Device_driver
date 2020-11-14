#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_VERSION("1:3.0");
MODULE_DESCRIPTION("simple chardev example");



ssize_t ext0_file_read (struct file * pfile, char __user *buffer, size_t lenght, loff_t * offset)
{

	printk (KERN_INFO "Inside the Function: %s \r\n", __FUNCTION__);
	return lenght;
}

ssize_t ext0_file_write (struct file * pfile, const char __user * buffer, size_t lenght, loff_t * offset)
{

	printk (KERN_INFO "Inside the Function: %s \r\n", __FUNCTION__);
	return lenght;
}

int ext0_file_open (struct inode * pnode, struct file * pfile)
{
	
	printk (KERN_INFO "Inside the Function: %s \r\n", __FUNCTION__);
	return 0;
}

int ext0_file_release (struct inode * pnode, struct file * pfile)
{

	printk (KERN_INFO "Inside the function: %s \r\n", __FUNCTION__);
	return 0;

}


/* File operations structrure */
static struct file_operations ext0_file_operations =
{
	.owner   = THIS_MODULE,
	.open    = ext0_file_open,
	.read    = ext0_file_read,
	.write   = ext0_file_write,
	.release = ext0_file_release
};

static int __init ext0_hello_module_init(void)
{
	printk (KERN_INFO "Hello world \r\n");
	/* Registering the chardev */
	register_chrdev(240,                     /*Major number */
			"Mahi_dev",              /*Driverv designated name */
			&ext0_file_operations);  /* File operations instance*/
	return 0;
}


static void __exit ext0_hello_module_exit(void)
{
	printk (KERN_INFO "GoodBye world\r\n");
	/* Unregistring the chardev */
	unregister_chrdev(240, "Mahi_dev");
}


module_init(ext0_hello_module_init);
module_exit(ext0_hello_module_exit);
