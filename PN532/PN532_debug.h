#ifndef __DEBUG_H__
#define __DEBUG_H__

//#define DEBUG

#ifdef DEBUG

#include <zephyr/sys/printk.h>
#define DMSG(args...)       printk(args)
#define DMSG_STR(str)       printk(str)
#define DMSG_HEX(num)       printk(" "); printk("%x", (num>>4)&0x0F); printk("%x", num&0x0F)
#define DMSG_INT(num)       printk(" "); printk("%d", num)


#else
#define DMSG(args...)
#define DMSG_STR(str)
#define DMSG_HEX(num)
#define DMSG_INT(num)
#endif

#endif
