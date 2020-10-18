#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>


/*Module info */
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Mahendra Sondagar <mahendrasondagar08@gmail.com>");
MODULE_DESCRIPTION("Module parameters passing");
MODULE_VERSION("1:3.1");

/* Delaring the module parameter */
int count =1;
/*Adding the parameter to the module with the file permisson (R/W)*/
module_param(count , int, S_IRUSR | S_IWUSR);

/* Module init */
static int __init ext0_module_init(void)
{
	int index =0;
	for (index = 0; index < count ; index ++)
	{
	printk (KERN_INFO "Hello world : %d\r\n", index);
	}
	return 0;
}

/* Module exit */
static void __exit ext0_module_exit(void)
{
  int index =0;

  for (index = 0; index < count ; index ++)
  {
  printk (KERN_INFO "Goodbye world: %d\r\n", index);
  }
}


module_init(ext0_module_init);
module_exit(ext0_module_exit);

