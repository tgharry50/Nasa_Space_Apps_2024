/*
 * gsm.h
 *
 *  Created on: 6 paź 2024
 *      Author: majorbien
 */

#ifndef MAIN_GSM_H_
#define MAIN_GSM_H_

#define MODEM_UART_NUM UART_NUM_1
#define MODEM_TX_PIN 17
#define MODEM_RX_PIN 16
#define MODEM_UART_BAUD_RATE 9600
#define BUF_SIZE 1024



void send_at_command(const char *command);

void receive_modem_response();

void send_sms(const char *phone_number, const char *message);

void init_sim800l();

void init_uart();


#endif /* MAIN_GSM_H_ */
