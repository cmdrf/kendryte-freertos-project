/* NOTE: The timer runs with a factor 50 slower than the CPU clock. In order
to get the desired tick rate, you must either multiply configTICK_RATE_HZ by 50
or divide configCPU_CLOCK_HZ by 50. Not sure which is better. */
#define configCPU_CLOCK_HZ			400000000 // NOTE: This must be adjusted if you change the CPU frequency
#define configTICK_RATE_HZ			( ( TickType_t ) 1000 * 50 )

#define configMTIME_BASE_ADDRESS		( 0x200bff8UL )
#define configMTIMECMP_BASE_ADDRESS		( 0x2004000UL ) // Core 0

#define configUSE_MUTEXES			1
#define configUSE_RECURSIVE_MUTEXES		0

#define configMAX_PRIORITIES			( 5 )
#define configUSE_PREEMPTION			1
#define configUSE_16_BIT_TICKS			0
#define configUSE_IDLE_HOOK			0
#define configUSE_TICK_HOOK			0

#define configISR_STACK_SIZE_WORDS ( 500 )
#define configMINIMAL_STACK_SIZE		( ( unsigned short ) 1024 )
#define configTOTAL_HEAP_SIZE			( ( size_t ) ( 1024 * 1024 ) )

#define configUSE_TICKLESS_IDLE			0

/* Set the following definitions to 1 to include the API function, or zero to exclude the API function. */
#define INCLUDE_vTaskPrioritySet				1
#define INCLUDE_uxTaskPriorityGet				1
#define INCLUDE_vTaskDelete						1
#define INCLUDE_vTaskCleanUpResources			1
#define INCLUDE_vTaskSuspend					1
#define INCLUDE_vTaskDelayUntil					1
#define INCLUDE_vTaskDelay						1
#define INCLUDE_eTaskGetState					1
#define INCLUDE_xTaskAbortDelay					1
#define INCLUDE_xTaskGetSchedulerState          1
#define INCLUDE_xTimerPendFunctionCall          0

// TODO: Fill in the rest
