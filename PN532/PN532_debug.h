#ifndef __DEBUG_H__
#define __DEBUG_H__

//#define DEBUG

#ifdef DEBUG

#ifdef ARDUINO
#include "Arduino.h"
#define DMSG(args...)       Serial.print(args)
#define DMSG_STR(str)       Serial.println(str)
#define DMSG_HEX(num)       Serial.print(' '); Serial.print((num>>4)&0x0F, HEX); Serial.print(num&0x0F, HEX)
#define DMSG_INT(num)       Serial.print(' '); Serial.print(num)

#else
#include <zephyr/sys/printk.h>
#define DMSG(args...)       printk(args)
#define DMSG_STR(str)       printk(str)
#define DMSG_HEX(num)       printk(" "); printk("%x", (num>>4)&0x0F); printk("%x", num&0x0F)
#define DMSG_INT(num)       printk(" "); printk("%d", num)
#endif

#else
#define DMSG(args...)
#define DMSG_STR(str)
#define DMSG_HEX(num)
#define DMSG_INT(num)
#endif

#endif
