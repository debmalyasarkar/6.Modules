#include <linux/init.h>
#include <linux/module.h>

int shared_counter = 0;

int myexport(void)
{
  printk("%s\n",__func__);
  shared_counter = 12;
  return 0;
}

int init_module(void)
{
  printk("%s\n",__func__);
  return 0;
}

void cleanup_module(void)
{
  printk("%s\n",__func__);
}

/* These two Symbols are Exported */
EXPORT_SYMBOL_GPL(shared_counter);
EXPORT_SYMBOL(myexport);

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Export Symbols Module");
MODULE_LICENSE("GPL");
