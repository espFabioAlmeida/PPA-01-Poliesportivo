///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    SubrotinasPlacar
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
COMANDOS TIME A
==============================================================================*/
void comandosTimeA() {

	switch(comandoPlacar) {
		case TIMEA_1: pontosEquipeA ++; break;
		case TIMEA_2: pontosEquipeA += 2; break;
		case TIMEA_3: pontosEquipeA += 3; break;
		case TIMEA_M1: pontosEquipeA --; break;

		case TIMEA_FALTA_1: faltasEquipeA ++; break;
		case TIMEA_FALTA_M1: faltasEquipeA --; break;
	}

	if(pontosEquipeA > 999) {
		pontosEquipeA = 0;
	}

	if(faltasEquipeA > 9) {
		faltasEquipeA = 0;
	}
}
/*==============================================================================
COMANDOS TIME B
==============================================================================*/
void comandosTimeB() {

	switch(comandoPlacar) {
		case TIMEB_1: pontosEquipeB ++; break;
		case TIMEB_2: pontosEquipeB += 2; break;
		case TIMEB_3: pontosEquipeB += 3; break;
		case TIMEB_M1: pontosEquipeB --; break;

		case TIMEB_FALTA_1: faltasEquipeB ++; break;
		case TIMEB_FALTA_M1: faltasEquipeB --; break;
	}

	if(pontosEquipeB > 999) {
		pontosEquipeB = 0;
	}

	if(faltasEquipeB > 9) {
		faltasEquipeB = 0;
	}
}
/*==============================================================================
COMANDOS CRONOMETRO
==============================================================================*/
void comandosCronometro() {

	switch(comandoPlacar) {
		case SOLTA_CRONOMETRO:
			if(!flagCronometroEstourado) {
				flagCronometro = true;
			}
			break;

		case PARA_CRONOMETRO: flagCronometro = false; break;
		case PERIODO_1: periodo ++; break;
		case PERIODO_M1: periodo --; break;

		case CAMPAINHA:
			if(!flagCronometro) {
				flagCampainha = true;
			}
			break;

		case ZERA_FALTA:
			if(!flagCronometro) {
				faltasEquipeA = 0;
				faltasEquipeB = 0;
			}
			break;

		case ZERA_CRONOMETRO:
			if(!flagCronometro) {
				zeraCronometro();
			}
			break;

		case ZERA_TUDO:
			if(!flagCronometro) {
				faltasEquipeA = 0;
				faltasEquipeB = 0;
				pontosEquipeA = 0;
				pontosEquipeB = 0;
				periodo = 1;
				zeraCronometro();
			}
			break;
	}
}
/*==============================================================================
CONTROLE PLACAR
==============================================================================*/
void controlePlacar() {

	if(comandoPlacar == SEM_COMANDO) {
		return;
	}

	comandosTimeA();
	comandosTimeB();
	comandosCronometro();

	comandoPlacar = SEM_COMANDO;
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
