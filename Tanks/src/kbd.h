#ifndef __KBD_H
#define __KBD_H

#include "i8042.h"
#include <minix/syslib.h>
#include <minix/drivers.h>
#include <minix/sysutil.h>
#include <stdbool.h>

#define KBD_IRQ		1
#define BIT(n) (0x01<<(n))
#define PAR_ERR BIT(7)
#define TO_ERR BIT(5)
#define OBF BIT(0)
#define IBF BIT(1)

int kbd_read();
int kbd_subscribe_int(void );
int kdb_unsubscribe_int();
int kbd_write(unsigned char command);
int kbd_scan(unsigned long key_code);

#endif /* _KBD_H */
