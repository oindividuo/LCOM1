#include <minix/drivers.h>
#include <minix/syslib.h>
#include "stdbool.h"
#include "i8042.h"
#include "i8254.h"
#include "mouse.h"
#include "timer.h"
#include "kbd.h"
#include "tank.h"

int main(int argc, char **argv) {

	/* Initialize service */

	sef_startup();
	int ipc_status, r, irq_kbd = 0, irq_timer = 0, irq_mouse = 0, time_counter = 0;
	bool endGame = false;
	unsigned long key;
	message msg;
	char *video_mem;
	video_mem = vg_init(mode);
	irq_timer = timer_subscribe_int();
	irq_kbd = kbd_subscribe_int();
	irq_mouse = ms_subscribe_int();

	if (irq_timer == -1 || irq_kbd == -1 || irq_mouse == -1)
		return 1;

	irq_kbd = BIT(irq_kbd);
	irq_timer = BIT(irq_timer);
	irq_mouse = BIT(irq_mouse);

	Tank *playerTank;
	playerTank = malloc(sizeof(Tank));
	playerTank = initTank();

	while (!endGame) {  //Interrupt loop
		/* Get a request message. */
		r = driver_receive(ANY, &msg, &ipc_status);
		if (r != 0) {
			printf("driver_receive failed with: %d", r);
			continue;
		}
		if (is_ipc_notify(ipc_status)) { /* received notification */
			switch (_ENDPOINT_P(msg.m_source)) {
			case HARDWARE: /* hardware interrupt notification */
				if (msg.NOTIFY_ARG & irq_kbd) {
				}
				if (msg.NOTIFY_ARG & irq_timer) {
				}
				break;
			default:
				break; /* no other notifications expected: do nothing */
			}
		} else { /* received a standard message, not a notification */
			/* no standard messages expected: do nothing */
		}
	}
    ms_unsubscribe_int();
	timer_unsubscribe_int();
	if (vg_exit() != 0)
		return 1;
	if (kdb_unsubscribe_int() != 0)
		return 1;

	return 0;

}
