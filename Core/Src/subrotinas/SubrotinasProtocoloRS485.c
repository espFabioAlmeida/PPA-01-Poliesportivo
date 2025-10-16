///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasProtocoloRS485
//AUTOR:      Fábio Almeida
//CRIADO:     16/10/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONFIGURAÇÃO CRONOMETRO
==============================================================================*/
void comandoConfiguracaoCronometro(uint8_t offset) {
	//$,01,20000,00000,1,\r\n
	if(flagCronometro) { //Somente se estiver com o tempo parado
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

	//TODO: SALVAR INFORMAÇÕES
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
		}
	}

	limpaRS485Buffer();
	flagPacoteRS485 = false;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
