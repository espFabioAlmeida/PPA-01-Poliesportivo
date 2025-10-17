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
#define TEMPO_CAMPAINHA 10

typedef struct {
	uint8_t minutos;
	uint8_t segundos;
	uint8_t decimais;
} CronometroTypeDef;

enum TIPO_CRONOMETRO {
	REGRESSIVO,
	PROGRESSIVO
};

enum COMANDO_PLACAR {
	SEM_COMANDO,
	TIMEA_1,
	TIMEA_2,
	TIMEA_3,
	TIMEA_M1,
	TIMEA_FALTA_1,
	TIMEA_FALTA_M1,
	TIMEA_TEMPO,

	TIMEB_1,
	TIMEB_2,
	TIMEB_3,
	TIMEB_M1,
	TIMEB_FALTA_1,
	TIMEB_FALTA_M1,
	TIMEB_TEMPO,

	SOLTA_CRONOMETRO,
	PARA_CRONOMETRO,
	CAMPAINHA,
	ZERA_FALTA,
	ZERA_CRONOMETRO,
	ZERA_TUDO,
	PERIODO_1,
	PERIODO_M1
};

extern UART_HandleTypeDef
	huart2;
extern I2C_HandleTypeDef
	hi2c1;

extern CronometroTypeDef
	cronometro,
	setpointCronometro;

extern uint8_t
	flagLedCPU,
	flagLedCOM,

	flagCampainha,
	flagCronometro,
	flagCronometroEstourado,
	flagCronometroZerado,

	flagPacoteRS485;

extern uint8_t
	faltasEquipeA,
	faltasEquipeB,
	periodo,
	tipoCronometro,

	comandoPlacar,

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
