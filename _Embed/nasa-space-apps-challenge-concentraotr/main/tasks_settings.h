/*
 * tasks_settings.h
 *
 *  Created on: 5 paź 2024
 *      Author: majorbien
 */

#ifndef MAIN_TASKS_SETTINGS_H_
#define MAIN_TASKS_SETTINGS_H_



// LoraWAN Send task
#define LORA_RECEIVE_STACK_SIZE				4096
#define LORA_RECEIVE_PRIORITY				5
#define LORA_RECEIVE_CORE_ID				0

// Wifi task
#define WIFI_STACK_SIZE					    4096	
#define WIFI_PRIORITY						4
#define WIFI_CORE_ID						1

//Http task
#define HTTP_STACK_SIZE						4096
#define HTTP_PRIORITY						3
#define HTTP_CORE_ID						1




#endif /* MAIN_TASKS_SETTINGS_H_ */