/**
 * @file: driver.c
 * @breif: Kernel module for a simple character driver, 
 * which solves the problem in the problem.md document
 *
 */
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/init.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define EASY_CHAR_BASE_MINOR 0 
#define EASY_CHAR_COUNT_OF_MINORS 1 
#define EASY_CHAR_NAME "easy-char-module" 

static dev_t easy_char_dev; 
static struct cdev *easy_char_cdev; 
static struct class *easy_char_class;
static struct device *char_dev;

static int mycdrv_open(struct inode *inode, struct file *file)
{
	dev_info(char_dev, " attempting to open device: %s:\n", EASY_CHAR_NAME);

	return 0;
}

static int mycdrv_release(struct inode *inode, struct file *file)
{
	dev_info(char_dev, " CLOSING device: %s:\n\n", EASY_CHAR_NAME);
	return 0;
}

static ssize_t
mycdrv_read(struct file *file, char __user *buf, size_t lbuf, loff_t *ppos)
{
	dev_info(char_dev, " Reading device: %s:\n\n", EASY_CHAR_NAME);
	return 0;
}

static ssize_t
mycdrv_write(struct file *file, const char __user *buf, size_t lbuf,
	     loff_t *ppos)
{
	dev_info(char_dev, " Writing device: %s:\n\n", EASY_CHAR_NAME);
	return 0;
}

static const struct file_operations easy_char_fops = {
	.owner = THIS_MODULE,
	.read = mycdrv_read,
	.write = mycdrv_write,
	.open = mycdrv_open,
	.release = mycdrv_release,
};

static int __init easy_char_module_init(void)
{
	printk(KERN_INFO "ESYCHAR: Module init.\n");

	/* Reserve Major/ Minor number  
	 * Here we are using dynamic allocation of major number, dynamic allocation is done using
	 * alloc_chrdev_region()
	 */
	if(alloc_chrdev_region(&easy_char_dev, 0, EASY_CHAR_COUNT_OF_MINORS, "easy-char-module") < 0) {
		/* Error Occured */
		printk(KERN_INFO "ESYCHAR: Failed to dynamically allocate Major and minor number\n");
		return -1;
	}

	/* Allocate cdev struct */
	easy_char_cdev = cdev_alloc();
	if (!easy_char_cdev) {
		printk(KERN_INFO, "ESYCHAR: Failed to alloc cdev.");
		unregister_chrdev_region(easy_char_dev, EASY_CHAR_COUNT_OF_MINORS);
		return -1;
	}
	
	/* Initialize the Char device */
	cdev_init(easy_char_cdev, &easy_char_fops);

	/* Add the char dirver to the linux kernel */
	if(cdev_add(easy_char_cdev, easy_char_dev, EASY_CHAR_COUNT_OF_MINORS) < 0) {
		printk(KERN_INFO, "ESYCHAR: Failed to add cdev.");
		cdev_del(easy_char_cdev);
		unregister_chrdev_region(easy_char_dev, EASY_CHAR_COUNT_OF_MINORS);
		return -1;
	}

	/* Create a class */

	easy_char_class = class_create("easy_char_class");

	/* Create the /dev/ device node */
	char_dev = device_create(easy_char_class,
			NULL, /* no parent device */
			easy_char_dev,
			NULL,/* no additional data */
			EASY_CHAR_NAME "%d", 0); /* Device node name is easy-char-module0 */

	dev_info(char_dev, "\nSucceeded in registering character device %s\n",
		 EASY_CHAR_NAME);
	dev_info(char_dev, "Major number = %d, Minor number = %d\n", MAJOR(easy_char_dev),
		 MINOR(easy_char_dev));

	return 0;
}

static void __exit easy_char_module_exit(void)
{
	printk(KERN_INFO "ESYCHAR: Module cleanup\n");

	/* Destroy the dev class*/
	device_destroy(easy_char_class, easy_char_dev);
	/* Destroy the class */
	class_destroy(easy_char_class);

	if (easy_char_cdev){
		cdev_del(easy_char_cdev);
	}
	unregister_chrdev_region(easy_char_dev, EASY_CHAR_COUNT_OF_MINORS);
}

module_init(easy_char_module_init);
module_exit(easy_char_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yogesh Hegde");
MODULE_DESCRIPTION("Easy Char kernel module!");