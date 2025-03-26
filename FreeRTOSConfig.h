#ifndef _CONFIG_H__
#define _CONFIG_H__

#define configTICK_TYPE_WIDTH_IN_BITS TICK_TYPE_WIDTH_32_BITS
#define configMAX_SYSCALL_INTERRUPT_PRIORITY 8
#define configMINIMAL_STACK_SIZE 128
#define configMAX_PRIORITIES 4
#define configUSE_PREEMPTION 1
#define configUSE_IDLE_HOOK 0
#define configUSE_TICK_HOOK 0

#define configCPU_CLOCK_HZ 12000
#define configTICK_RATE_HZ 1000
#define configTOTAL_HEAP_SIZE 1024

#endif
