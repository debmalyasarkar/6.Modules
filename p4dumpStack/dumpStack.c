#include <linux/init.h>
#include <linux/module.h>

/* dump_stack() shows the full chain of calls in the kernel logs once the 
   corresponding function is called */
int init_module(void)
{
  printk("%s\n",__func__);
  dump_stack();
  return 0;
}

void cleanup_module(void)
{
  printk("%s\n",__func__);
  dump_stack();
}

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Dump Stack Module");
MODULE_LICENSE("GPL");
