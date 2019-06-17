#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/miscdevice.h>
#include<asm/uaccess.h>
#define DEVICE_NAME "luming_test"

static struct file_operations dev_fops = {.owner = THIS_MODULE};

static struct miscdevice misc = {.minor = MISC_DYNAMIC_MINOR, .name = DEVICE_NAME, .fops = &dev_fops};


static int word_count_init(void)
{
	int ret;
	ret = misc_register(&misc);
	printk("word count init  success\n");
	return ret;
}
static void word_count_exit(void)
{
	misc_deregister(&misc);
	printk("word count exit success\n");
}

module_init(word_count_init);
module_exit(word_count_exit);
MODULE_AUTHOR("luming");
MODULE_DESCRIPTION("test driver");
MODULE_ALIAS("test");
MODULE_LICENSE("GPL");
