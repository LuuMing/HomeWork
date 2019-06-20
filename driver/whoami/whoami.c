#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/fs.h>
#include<linux/miscdevice.h>
#include<linux/uaccess.h>
#include<linux/delay.h>
#define DEVICE_NAME "whoami"

static unsigned char mem[100];
static int written_count = 0;
static DEFINE_RWLOCK(rwlock);
struct rw_semaphore rw_sem;
static ssize_t whoamiread(struct file * file, char __user *buf, size_t count, loff_t *ppos)
{
	//read_lock(&rwlock);
	down_read(&rw_sem);
	copy_to_user(buf, (void*)mem, written_count);
	mdelay(5000);
	printk("read count: %d",(int)written_count);
	//read_unlock(&rwlock);
	up_read(&rw_sem);
	return written_count;
}

static ssize_t whoamiwrite(struct file * file, const char __user *buf, size_t count, loff_t *ppos)
{
	//write_lock(&rwlock);
	down_write(&rw_sem);
	copy_from_user(mem, buf,count);
	mdelay(5000);
	up_write(&rw_sem);
	//write_unlock(&rwlock);
	written_count = count;
	return count;
}

static struct file_operations dev_fops = {.owner = THIS_MODULE, .read = whoamiread, .write = whoamiwrite};

static struct miscdevice misc = {.minor = MISC_DYNAMIC_MINOR, .name = DEVICE_NAME, .fops = &dev_fops};


static int word_count_init(void)
{
	int ret;
	ret = misc_register(&misc);
	printk("whoami init  success\n");
	init_rwsem(&rw_sem);
	return ret;
}
static void word_count_exit(void)
{
	misc_deregister(&misc);
	printk("whoami exit success\n");
}

module_init(word_count_init);
module_exit(word_count_exit);
MODULE_AUTHOR("luming");
MODULE_DESCRIPTION("test driver");
MODULE_ALIAS("test");
MODULE_LICENSE("GPL");
