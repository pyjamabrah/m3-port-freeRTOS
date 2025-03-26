#include "FreeRTOS.h"
#include "queue.h"
#include "task.h"

static void vTask1(void *pvParameters) {
  while (1) {

  };
}

static void vTask2(void *pvParameters) {
  while (1) {

  };
}

void main() {
  xTaskCreate(vTask1, "T1", configMINIMAL_STACK_SIZE, (void *)0, tskIDLE_PRIORITY, (void *)0);
  xTaskCreate(vTask2, "T2", configMINIMAL_STACK_SIZE, (void *)0, tskIDLE_PRIORITY, (void *)0);

  vTaskStartScheduler();
  return;
}
