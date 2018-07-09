#include <linux/init.h>
#include <linux/module.h>

int hello_module(void)
{
  printk("%s\n",__func__);
  return 0;
}

/* Entry Function */
int init_module(void)
{
  printk("%s\n",__func__);
  hello_module();
  return 0;
}

/* Exit Function */
void cleanup_module(void)
{
  printk("%s\n",__func__);
}

/* Comments which are retained in code */
MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Hello World Module");
MODULE_LICENSE("GPL");

/* This functions enable us to use custom init and exit function names */
//module_init(myinit);
//module_exit(myexit);
