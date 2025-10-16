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

#define TAMANHO_RS485_BUFFER  64

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
	flagLedCOM,

	flagCronometro,
	flagPacoteRS485;

extern uint8_t
	faltasEquipeA,
	faltasEquipeB,
	periodo,

	contadorRS485Buffer;

extern char
	rs485DataIn;

extern uint16_t
	pontosEquipeA,
	pontosEquipeB;

extern uint8_t
	displaysCronometro[5],
	displaysEquipeA[5],
	displaysEquipeB[5];

extern char
	rs485Buffer[TAMANHO_RS485_BUFFER];

#endif /* INC_GLOBAL_H_ */
