//#include "RTOS_task.h"
#define sdCardWriteTaskIndicater (8)
#define onBoardComTaskIndicater (7)
#define uartForAppUpdateTaskIndicater (4)
#define sysTickIndicater (6)
#define shedulerIndicater (5)

//for setup
for(int i =4 ; i<=8 ;i++)
{
	pinMode(i,OUTPUT);
	delay(10);
}

taskInit();
vTaskStartScheduler();

//for loop

while(1);

void taskInit(void)
{
	if(xTaskCreate(onBoardComTask, \
	"onboardComTask",100,(void*)0,1,(TaskHandle_t *)0) != pdPASS)
	{
		printf("onBoardComTask task not created!");
	}
	
	if(xTaskCreate(sdCardWriteTask, \
	"sdCardWriteTask",100,(void*)0,1,(TaskHandle_t *)0) != pdPASS)
	{
		printf("sdCardWriteTask task not created!");
	}
	
	if(xTaskCreate(uartForAppUpdateTask, \
	"uartForAppUpdateTask",100,(void*)0,1,(TaskHandle_t *)0) != pdPASS)
	{
		printf("uartForAppUpdateTask task not created!");
	}
	
}

void onBoardComTask(void)
{
  while(1)
  {
	  digitalWrite(onBoardComTaskIndicater , HIGH);
	  vTaskDelay(5);
	  
	  digitalWrite(onBoardComTaskIndicater , LOW);
	  vTaskDelay(5);
  }
}

void sdCardWriteTask(void)
{
  while(1)
  {
	 digitalWrite(sdCardWriteTaskIndicater , HIGH);
	 vTaskDelay(5);
	  
	 digitalWrite(sdCardWriteTaskIndicater , LOW);
	 vTaskDelay(5);
  }
  
}

void uartForAppUpdateTask(void)
{
  while(1)
  {
	digitalWrite(uartForAppUpdateTaskIndicater , HIGH);
	vTaskDelay(5);
	  
	digitalWrite(uartForAppUpdateTaskIndicater , LOW);  
	vTaskDelay(5);
  }
}
