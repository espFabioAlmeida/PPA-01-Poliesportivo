///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasProtocoloRS485
//AUTOR:      Fábio Almeida
//CRIADO:     16/10/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
#include "string.h"
/*==============================================================================
ENVIA RESPOSTA
==============================================================================*/
void enviaRespostaRS485(uint8_t comando) {
	char bufferEnviaRS485[9];
	char dataChar[4];
	memset(bufferEnviaRS485, 0x00, 9);
	memset(dataChar, 0x00, 4);

	if(!comando) {
		return;
	}
	sprintf(dataChar, "%u", comando);

	strcat(bufferEnviaRS485, "$,");
	if(comando <= 9) {
		strcat(bufferEnviaRS485, "0");
	}
	strcat(bufferEnviaRS485, dataChar);
	strcat(bufferEnviaRS485, ",\r\n");

	HAL_UART_Transmit(&huart2, &bufferEnviaRS485, strlen(bufferEnviaRS485), 200);
}
/*==============================================================================
CONFIGURAÇÃO CRONOMETRO
==============================================================================*/
void comandoConfiguracaoCronometro(uint8_t offset) {
	//$,01,20000,00000,1,\r\n
	if(flagCronometro && !flagCronometroZerado) { //Somente se estiver com o tempo parado
		return;
	}
	setpointCronometro.minutos = charToByte(rs485Buffer[offset + 5]) * 10;
	setpointCronometro.minutos += charToByte(rs485Buffer[offset + 6]);
	setpointCronometro.segundos = charToByte(rs485Buffer[offset + 7]) * 10;
	setpointCronometro.segundos += charToByte(rs485Buffer[offset + 8]);
	setpointCronometro.decimais = charToByte(rs485Buffer[offset + 9]);

	cronometro.minutos = charToByte(rs485Buffer[offset + 11]) * 10;
	cronometro.minutos += charToByte(rs485Buffer[offset + 12]);
	cronometro.segundos = charToByte(rs485Buffer[offset + 13]) * 10;
	cronometro.segundos += charToByte(rs485Buffer[offset + 14]);
	cronometro.decimais = charToByte(rs485Buffer[offset + 15]);

	if(rs485Buffer[offset + 17] == '1') {
		tipoCronometro = REGRESSIVO;
	}
	else if(rs485Buffer[offset + 17] == '2') {
		tipoCronometro = PROGRESSIVO;
	}

	salvaCronometro();
	salvaSetpointCronometro();
}
/*==============================================================================
AJUSTE PONTOS
==============================================================================*/
void comandoAjustePontos(uint8_t offset) {
	//$,50,025,078,\r\n
	if(flagCronometro) { //Somente se estiver com o tempo parado
		return;
	}

	pontosEquipeA = charToByte(rs485Buffer[offset + 5]);
	pontosEquipeA *= 100;
	pontosEquipeA += charToByte(rs485Buffer[offset + 6]) * 10;
	pontosEquipeA += charToByte(rs485Buffer[offset + 7]);

	pontosEquipeB = charToByte(rs485Buffer[offset + 9]);
	pontosEquipeB *= 100;
	pontosEquipeB += charToByte(rs485Buffer[offset + 10]) * 10;
	pontosEquipeB += charToByte(rs485Buffer[offset + 11]);

	salvaDadosPlacar();
}
/*==============================================================================
PROTOCOLO RS485
==============================================================================*/
void protocoloRS485() {
	signed int offset = 0;
	uint8_t comando = 0;

	if(!flagPacoteRS485) {
		return;
	}

	offset = indexOf(rs485Buffer, "$,");

	if(offset >= 0) {
		comando = charToByte(rs485Buffer[offset + 2]) * 10;
		comando += charToByte(rs485Buffer[offset + 3]);

		switch(comando) {
			case 1: comandoConfiguracaoCronometro(offset); break;

			case 2: comandoPlacar = TIMEA_1; break;
			case 3: comandoPlacar = TIMEA_2; break;
			case 4: comandoPlacar = TIMEA_3; break;
			case 5: comandoPlacar = TIMEA_M1; break;
			case 6: comandoPlacar = TIMEA_FALTA_1; break;
			case 7: comandoPlacar = TIMEA_FALTA_M1; break;
			case 8: comandoPlacar = TIMEA_TEMPO; break;

			case 9: comandoPlacar = TIMEB_1; break;
			case 10: comandoPlacar = TIMEB_2; break;
			case 11: comandoPlacar = TIMEB_3; break;
			case 12: comandoPlacar = TIMEB_M1; break;
			case 13: comandoPlacar = TIMEB_FALTA_1; break;
			case 14: comandoPlacar = TIMEB_FALTA_M1; break;
			case 15: comandoPlacar = TIMEB_TEMPO; break;

			case 16: comandoPlacar = SOLTA_CRONOMETRO; break;
			case 17: comandoPlacar = PARA_CRONOMETRO; break;
			case 18: comandoPlacar = CAMPAINHA; break;
			case 19: comandoPlacar = ZERA_FALTA; break;
			case 20: comandoPlacar = ZERA_CRONOMETRO; break;
			case 21: comandoPlacar = ZERA_TUDO; break;
			case 22: comandoPlacar = PERIODO_1; break;
			case 23: comandoPlacar = PERIODO_M1; break;

			case 50: comandoAjustePontos(offset); break;

			default: comandoPlacar = SEM_COMANDO; break;
		}
	}

	enviaRespostaRS485(comando);

	limpaRS485Buffer();
	flagPacoteRS485 = false;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
