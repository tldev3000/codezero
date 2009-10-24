#ifndef __PLATFORM_PB926_PLATFORM_H__
#define __PLATFORM_PB926_PLATFORM_H__
/*
 * Platform specific ties between drivers and generic APIs used by the kernel.
 * E.g. system timer and console.
 *
 * Copyright (C) Bahadir Balban 2007
 */

#include INC_PLAT(offsets.h)
#include INC_GLUE(memlayout.h)

#define PLATFORM_CONSOLE_BASE			PB926_UART0_VBASE

/* SP804 timer has TIMER1 at TIMER0 + 0x20 address */
#define PLATFORM_TIMER0_BASE		PB926_TIMER01_VBASE

#define PLATFORM_SP810_BASE			PB926_SYSCTRL_VBASE
#define PLATFORM_IRQCTRL_BASE			PB926_VIC_VBASE
#define PLATFORM_SIRQCTRL_BASE			PB926_SIC_VBASE

/* Total number of timers present in this platform */
#define	TOTAL_TIMERS			4

#define PLATFORM_TIMER0	0
#define PLATFORM_TIMER1	1
#define PLATFORM_TIMER2	2
#define PLATFORM_TIMER3	3

void platform_irq_enable(int irq);
void platform_irq_disable(int irq);
void timer_start(void);
#endif /* __PLATFORM_PB926_PLATFORM_H__ */
