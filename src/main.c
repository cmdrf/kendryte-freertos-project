#include <fpioa.h>
#include <gpio.h>
#include <sysctl.h>

#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>

#include <stdbool.h>
#include <stdio.h>

void LedTask(void* p)
{
	QueueHandle_t queue = (QueueHandle_t)p;

	fpioa_set_function(12, FUNC_GPIO3);

	gpio_init();
	gpio_set_drive_mode(3, GPIO_DM_OUTPUT);

	while(true)
	{
		bool state;
		xQueueReceive(queue, &state, portMAX_DELAY);
		gpio_set_pin(3, state ? GPIO_PV_HIGH : GPIO_PV_LOW);

	}
}

void ControlTask(void* p)
{
	QueueHandle_t queue = (QueueHandle_t)p;

	bool state = false;
	while(true)
	{
		xQueueSend(queue, &state, portMAX_DELAY);
		state = !state;
		vTaskDelay(500);
	}
}

int main()
{
	sysctl_pll_set_freq(SYSCTL_PLL0, configCPU_CLOCK_HZ * 2);
	QueueHandle_t queue = xQueueCreate( 10, sizeof(bool) );

	printf("Create tasks...\r\n");
	xTaskCreate(LedTask, "LedTask", 256, queue, 3, NULL);
	xTaskCreate(ControlTask, "ControlTask", 256, queue, 3, NULL);

	printf("Start scheduler...\r\n");
	vTaskStartScheduler();
}
