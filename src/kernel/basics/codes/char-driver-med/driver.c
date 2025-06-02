/**
 * @file: driver.c
 * @breif: Kernel module for a simple character driver
 *
 */
#include <linux/module.h>  
#include <linux/kernel.h>  
#include <linux/init.h>

static int __init panic_module_init(void)
{
	printk(KERN_INFO "Hello module init.\n");
	//int *p = 1;
	//printk("%d\n", *p);
	return 0;
}

static void __exit panic_module_exit(void)
{
	printk(KERN_INFO "Panic module cleanup\n");
}

module_init(panic_module_init);
module_exit(panic_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yogesh Hegde");
MODULE_DESCRIPTION("Panic kernel module!");