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
VERIFICACAO INICIAL CRONOMETRO
==============================================================================*/
void verificacaoInicialCronometro() {
	if(tipoCronometro == REGRESSIVO) {
		if(cronometro.minutos == setpointCronometro.minutos &&
				cronometro.segundos == setpointCronometro.segundos &&
				cronometro.decimais == setpointCronometro.decimais) {
			flagCronometroZerado = true;
		}

		if(!cronometro.minutos && !cronometro.segundos && !cronometro.decimais) {
			flagCronometroEstourado = true;
		}
		return;
	}

	if(!cronometro.minutos && !cronometro.segundos && !cronometro.decimais) {
		flagCronometroZerado = true;
	}

	if(cronometro.minutos == setpointCronometro.minutos &&
			cronometro.segundos == setpointCronometro.segundos &&
			cronometro.decimais == setpointCronometro.decimais) {
		flagCronometroEstourado = true;
	}
}
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

	flagCronometroEstourado = false;
	flagCronometroZerado = true;
}
/*==============================================================================
CONTROLE CRONOMETRO
==============================================================================*/
void controleCronometro() {

	if(!flagCronometro) {
		return;
	}

	flagCronometroZerado = false;

	if(tipoCronometro == REGRESSIVO) {
		if(cronometro.minutos <= 99) {
			cronometro.decimais --;
			if(cronometro.decimais > 9) {
				cronometro.decimais = 9;
				cronometro.segundos --;
				if(cronometro.segundos > 59) {
					cronometro.segundos = 59;
					cronometro.minutos --;
					if(cronometro.minutos > 99) {
						flagCronometro = false;
						flagCronometroEstourado = true;
						flagCampainha = true;

						cronometro.minutos = 0;
						cronometro.segundos = 0;
						cronometro.decimais = 0;
					}
				}
			}
		}
		else {
			flagCronometro = false;
			flagCronometroEstourado = true;
			flagCampainha = true;

			cronometro.minutos = 0;
			cronometro.segundos = 0;
			cronometro.decimais = 0;
		}

		return;
	}


	if(cronometro.minutos < setpointCronometro.minutos) {
		cronometro.decimais ++;
		if(cronometro.decimais > 9) {
			cronometro.decimais = 0;
			cronometro.segundos ++;
			if(cronometro.segundos > 59) {
				cronometro.segundos = 0;
				cronometro.minutos ++;
				if(cronometro.minutos >= setpointCronometro.minutos) {
					flagCronometro = false;
					flagCronometroEstourado = true;
					flagCampainha = true;

					cronometro.minutos = setpointCronometro.minutos;
					cronometro.segundos = setpointCronometro.segundos;
					cronometro.decimais = setpointCronometro.decimais;
				}
			}
		}
	}
	else {
		flagCronometro = false;
		flagCronometroEstourado = true;
		flagCampainha = true;

		cronometro.minutos = setpointCronometro.minutos;
		cronometro.segundos = setpointCronometro.segundos;
		cronometro.decimais = setpointCronometro.decimais;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
