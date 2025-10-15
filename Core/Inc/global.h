/*
 * global.h
 *
 *  Created on: Aug 23, 2023
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

enum BOOL {
	false,
	true
};

#define UART_BUFFER_SIZE  64

typedef struct {
	uint8_t minutos;
	uint8_t segundos;
	uint8_t decimais;
} CronometroTypeDef;

extern UART_HandleTypeDef
	huart2;
extern I2C_HandleTypeDef
	hi2c1;

extern CronometroTypeDef
	cronometro;

extern uint8_t
	flagLedCPU,
	flagLedCOM;

extern uint8_t
	faltasEquipeA,
	faltasEquipeB,
	periodo;

extern uint16_t
	pontosEquipeA,
	pontosEquipeB;

extern char
	uartBuffer[UART_BUFFER_SIZE];

#endif /* INC_GLOBAL_H_ */
