///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasDisplay
//AUTOR:      Fábio Almeida
//CRIADO:     16/10/2025
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
VARIAVEIS
==============================================================================*/
/*==============================================================================
APRESENTAÇÃO INICIAL
==============================================================================*/
void apresentacaoInicial() {

	for(uint16_t i = 9; i < 10; i --) {
		cronometro.decimais = i;
		cronometro.segundos = i * 11;
		cronometro.minutos = i * 11;

		periodo = i;
		faltasEquipeA = i;
		pontosEquipeA = i * 111;
		faltasEquipeB = i;
		pontosEquipeB = i * 111;
		HAL_Delay(500);
	}

	pontosEquipeA = 123;
	pontosEquipeB = 456;
	faltasEquipeA = 7;
	periodo = 8;
	faltasEquipeB = 9;

	cronometro.minutos = 12;
	cronometro.segundos = 34;
	cronometro.decimais = 5;
	HAL_Delay(1500);
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
