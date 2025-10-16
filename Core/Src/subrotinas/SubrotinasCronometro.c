///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasZeraCronometro
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
ZERA CRONOMETRO
==============================================================================*/
void zeraCronometro() {
	if(tipoCronometro == REGRESSIVO) {
		cronometro.minutos = setpointCronometro.minutos;
		cronometro.segundos = setpointCronometro.segundos;
		cronometro.decimais = setpointCronometro.decimais;
	}
	else {
		cronometro.minutos = 0;
		cronometro.segundos = 0;
		cronometro.decimais = 0;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
