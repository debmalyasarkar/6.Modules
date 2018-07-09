#include <linux/init.h>
#include <linux/module.h>

/* These symbols are expected to be exported by other modules */
extern int shared_counter;
extern int myexport(void);

int init_module(void)
{
  printk("%s\n",__func__);
  shared_counter = 10;
  myexport();
  return 0;
}

void cleanup_module(void)
{
  printk("%s\n",__func__);
}

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Dependent Module");
MODULE_LICENSE("GPL");
