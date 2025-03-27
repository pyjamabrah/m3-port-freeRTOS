#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

/* Register base addresses (from STM32F100 RM0041) */
#define RCC_BASE       0x40021000  // Reset and Clock Control
#define GPIOA_BASE     0x40010800  // GPIO Port A
#define GPIOC_BASE     0x40011000  // GPIO Port C
#define USART1_BASE    0x40013800  // USART1
#define FLASH_BASE     0x40022000  // Flash interface

/* RCC registers */
#define RCC_CR         (*(volatile uint32_t *)(RCC_BASE + 0x00))
#define RCC_CFGR       (*(volatile uint32_t *)(RCC_BASE + 0x04))
#define RCC_APB2ENR    (*(volatile uint32_t *)(RCC_BASE + 0x18))

/* GPIO registers */
#define GPIOA_CRH      (*(volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOC_CRH      (*(volatile uint32_t *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR      (*(volatile uint32_t *)(GPIOC_BASE + 0x0C))

/* USART1 registers */
#define USART1_SR      (*(volatile uint32_t *)(USART1_BASE + 0x00))
#define USART1_DR      (*(volatile uint32_t *)(USART1_BASE + 0x04))
#define USART1_BRR     (*(volatile uint32_t *)(USART1_BASE + 0x08))
#define USART1_CR1     (*(volatile uint32_t *)(USART1_BASE + 0x0C))

/* Flash registers */
#define FLASH_ACR      (*(volatile uint32_t *)(FLASH_BASE + 0x00))

/* Bit definitions (manual-specific) */
#define RCC_CR_HSEON   (1U << 16)
#define RCC_CR_HSERDY  (1U << 17)
#define RCC_CR_PLLON   (1U << 24)
#define RCC_CR_PLLRDY  (1U << 25)
#define RCC_CFGR_PLLSRC (1U << 16)
#define RCC_CFGR_PLLMULL3 (1U << 18) // PLL × 3
#define RCC_CFGR_SW_PLL (2U << 0)
#define RCC_CFGR_SWS_PLL (2U << 2)
#define RCC_APB2ENR_IOPAEN (1U << 2)
#define RCC_APB2ENR_IOPCEN (1U << 4)
#define RCC_APB2ENR_USART1EN (1U << 14)
#define FLASH_ACR_LATENCY_1 (1U << 1)
#define USART_CR1_UE   (1U << 13)
#define USART_CR1_TE   (1U << 3)
#define USART_SR_TXE   (1U << 7)


/* System clock: 24 MHz using HSE + PLL */
void SystemClock_Config(void) {
    /* Enable HSE */
    RCC_CR |= RCC_CR_HSEON;
    // while (!(RCC_CR & RCC_CR_HSERDY)); // Wait for HSE ready

    /* Configure PLL: HSE * 3 = 24 MHz */
    RCC_CFGR &= ~(0xF << 18); // Clear PLLMULL
    RCC_CFGR |= RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL3;
    RCC_CR |= RCC_CR_PLLON;
    // while (!(RCC_CR & RCC_CR_PLLRDY)); // Wait for PLL ready

    /* Set Flash latency for 24 MHz */
    FLASH_ACR |= FLASH_ACR_LATENCY_1;

    /* Switch to PLL as system clock */
    RCC_CFGR = (RCC_CFGR & ~(3U << 0)) | RCC_CFGR_SW_PLL;
    // while ((RCC_CFGR & RCC_CFGR_SWS_PLL) != RCC_CFGR_SWS_PLL); // Wait for switch
}

static void vTask1(void *pvParameters) {
  while (1) {

  };
}

static void vTask2(void *pvParameters) {
  while (1) {

  };
}

void main() {
  SystemClock_Config();

  xTaskCreate(vTask1, "T1", configMINIMAL_STACK_SIZE, (void *)0, 3, (void *)0);
  xTaskCreate(vTask2, "T2", configMINIMAL_STACK_SIZE, (void *)0, 3, (void *)0);

  vTaskStartScheduler();

  for (;;);

  return;
}
