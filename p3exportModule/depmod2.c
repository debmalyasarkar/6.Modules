#include <linux/init.h>
#include <linux/module.h>

/* Pointers used to load the exported symbols on runtime */
static int *ptr;
static int (*fptr)(void);

int init_module(void)
{
  printk("%s\n",__func__);

  ptr = (int *) __symbol_get("shared_counter");
  if(ptr)
  {
    *ptr = 10;
    __symbol_put("shared_counter");
  }
  else
  {
    pr_err("Symbol Not Found\n");
  }
  
  fptr = __symbol_get("myexport");
  if(fptr)
  {
    fptr();
    __symbol_put("myexport");
  }
  else
  {
    pr_err("Function Not Found\n");
  }
  return 0;
}

void cleanup_module(void)
{
  printk("%s\n",__func__);
}

MODULE_AUTHOR("debmalyasarkar1@gmail.com");
MODULE_DESCRIPTION("Dependent Module using Runtime Linkage");
MODULE_LICENSE("GPL");
