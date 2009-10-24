/*
 * Ties up platform timer with generic timer api
 *
 * Copyright (C) 2007 Bahadir Balban
 *
 */
#include <l4/generic/irq.h>
#include <l4/generic/platform.h>
#include INC_PLAT(platform.h)
#include <l4/drivers/timer/sp804/sp804_timer.h>
#include <l4/drivers/misc/sp810/sp810_sysctrl.h>

/* Microkernel is using TIMER0, so we will initialize only this one */
void timer_init(void)
{
	/* Set frequency of  timer to 1MHz */
	sp810_set_timclk(PLATFORM_TIMER0, 1);

	/* Initialise timer */
	sp804_init(PLATFORM_TIMER0_BASE, SP804_TIMER_RUNMODE_PERIODIC, \
		   SP804_TIMER_WRAPMODE_WRAPPING, SP804_TIMER_WIDTH32BIT, \
		   SP804_TIMER_IRQENABLE);
}

/* Microkernel is using TIMER0, so we will initialize only this one */
void timer_start(void)
{
	/* Enable irq line for TIMER0*/
	irq_enable(IRQ_TIMER01);

	/* Enable timer */
	sp804_enable(PLATFORM_TIMER0_BASE, 1);
}

