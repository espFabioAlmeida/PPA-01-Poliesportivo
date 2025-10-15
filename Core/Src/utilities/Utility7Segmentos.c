///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    Utility7Segmentos
//AUTOR:      Fábio Almeida
//CRIADO:     11/09/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
VARIAVEIS
==============================================================================*/
uint8_t displayPiscando = 0xFF;
uint8_t flagPD[4];
/*==============================================================================
DESENHA NUMERO
==============================================================================*/
void desenhaNumero(uint8_t valor, uint8_t pd) {
	uint8_t display = 0x00;

	switch(valor) {
		case 0: display = 0b01111110; break;
		case 1: display = 0b00110000; break;
		case 2: display = 0b01101101; break;
		case 3: display = 0b01111001; break;
		case 4: display = 0b00110011; break;
		case 5: display = 0b01011011; break;
		case 6: display = 0b01011111; break;
		case 7: display = 0b01110000; break;
		case 8: display = 0b01111111; break;
		case 9: display = 0b01111011; break;

		case ' ': display = 0b00000000; break;
		case 'A': display = 0b01110111; break;
		case 'B': display = 0b00011111; break;
		case 'C': display = 0b01001110; break;
		case 'D': display = 0b00111101; break;
		case 'E': display = 0b01001111; break;
		case 'F': display = 0b01000111; break;
		case 'G': display = 0b01011111; break;
		case 'H': display = 0b00110111; break;
		case 'I': display = 0b00010000; break;
		case 'J': display = 0b01111100; break;
		case 'K': display = 0b00100111; break;
		case 'L': display = 0b00001110; break;
		case 'M': display = 0b01110110; break;
		case 'N': display = 0b00010101; break;
		case 'O': display = 0b00011101; break;
		case 'P': display = 0b01100111; break;
		case 'Q': display = 0b01111110; break;
		case 'R': display = 0b00000101; break;
		case 'S': display = 0b01011011; break;
		case 'T': display = 0b00001111; break;
		case 'U': display = 0b00111110; break;
		case 'V': display = 0b00111110; break;
		case 'X': display = 0b00110111; break;
		case 'W': display = 0b00111110; break;
		case 'Y': display = 0b00111011; break;
		case 'Z': display = 0b01101101; break;

		case '+': display = 0b00110001; break;
		case '-': display = 0b00000001; break;
	}

	setPin(DISP_A_GPIO_Port, DISP_A_Pin, bitRead(display, 6));
	setPin(DISP_B_GPIO_Port, DISP_B_Pin, bitRead(display, 5));
	setPin(DISP_C_GPIO_Port, DISP_C_Pin, bitRead(display, 4));
	setPin(DISP_D_GPIO_Port, DISP_D_Pin, bitRead(display, 3));
	setPin(DISP_E_GPIO_Port, DISP_E_Pin, bitRead(display, 2));
	setPin(DISP_F_GPIO_Port, DISP_F_Pin, bitRead(display, 1));
	setPin(DISP_G_GPIO_Port, DISP_G_Pin, bitRead(display, 0));
	setPin(DISP_PD_GPIO_Port, DISP_PD_Pin, pd);
}
/*==============================================================================
DESLIGA DISPLAYS
==============================================================================*/
void desligaDisplays() {
	off(DISP_UNID_GPIO_Port, DISP_UNID_Pin);
	off(DISP_DEZE_GPIO_Port, DISP_DEZE_Pin);
	off(DISP_CENT_GPIO_Port, DISP_CENT_Pin);
	off(DISP_MILH_GPIO_Port, DISP_MILH_Pin);
}
/*==============================================================================
LIGA DISPLAY
==============================================================================*/
void ligaDisplay(uint8_t display) {
	switch(display) {
		case 3: on(DISP_UNID_GPIO_Port, DISP_UNID_Pin); break;
		case 2: on(DISP_DEZE_GPIO_Port, DISP_DEZE_Pin); break;
		case 1: on(DISP_CENT_GPIO_Port, DISP_CENT_Pin); break;
		case 0: on(DISP_MILH_GPIO_Port, DISP_MILH_Pin); break;
	}
}
/*==============================================================================
PONTO DECIMAL
==============================================================================*/
void pontoDcimal(uint8_t display, uint8_t pd) {
	flagPD[display] = pd;
}
/*==============================================================================
DESLIGA TODOS OS PONTOS DECIMAIS
==============================================================================*/
void desligaPontosDecimais() {
	flagPD[0] = false;
	flagPD[1] = false;
	flagPD[2] = false;
	flagPD[3] = false;
}
/*==============================================================================
PISCA DISPLAY
==============================================================================*/
void piscaDisplay(uint8_t display, uint8_t ativado) {
	if(ativado) {
		displayPiscando = display;
		return;
	}
	displayPiscando = 0xFF;
}
/*==============================================================================
APAGA DISPLAY
==============================================================================*/
void apagaDisplay() {
	display7Segmentos.unid = ' ';
	display7Segmentos.deze = ' ';
	display7Segmentos.cent = ' ';
	display7Segmentos.milh = ' ';
}
/*==============================================================================
ATUALIZA DISPLAY
==============================================================================*/
void atualizaDisplay() {
	static uint8_t display = 0, numero = 0;

	switch(display) {
		case 3: numero = display7Segmentos.unid; break;
		case 2: numero = display7Segmentos.deze; break;
		case 1: numero = display7Segmentos.cent; break;
		case 0: numero = display7Segmentos.milh; break;
	}

	desligaDisplays();


	if(flagPiscaDisplay || display != displayPiscando) {
		desenhaNumero(numero, flagPD[display]);
	}
	else {
		desenhaNumero(' ', flagPD[display]);
	}

	//desenhaNumero(numero, flagPD[display]);
	ligaDisplay(display);

	display ++;
	if(display > 3) {
		display = 0;
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
