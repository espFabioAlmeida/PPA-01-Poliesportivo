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
/*==============================================================================
DESENHA NUMERO
==============================================================================*/
uint8_t desenhaNumero(uint8_t valor) {
	uint8_t display = 0x00;

	switch(valor) {
		case 0: display = 0b11111100; break;
		case 1: display = 0b01100000; break;
		case 2: display = 0b11011010; break;
		case 3: display = 0b11110010; break;
		case 4: display = 0b01100110; break;
		case 5: display = 0b10110110; break;
		case 6: display = 0b10111110; break;
		case 7: display = 0b11100000; break;
		case 8: display = 0b11111110; break;
		case 9: display = 0b11110110; break;

		case ' ': display = 0b00000000; break;
		case 'A': display = 0b11101110; break;
		case 'B': display = 0b00111110; break;
		case 'C': display = 0b10011100; break;
		case 'D': display = 0b01111010; break;
		case 'E': display = 0b10011110; break;
		case 'F': display = 0b10001110; break;
		case 'G': display = 0b10111110; break;
		case 'H': display = 0b01101110; break;
		case 'I': display = 0b00100000; break;
		case 'J': display = 0b11111000; break;
		case 'K': display = 0b01001110; break;
		case 'L': display = 0b00011100; break;
		case 'M': display = 0b11101100; break;
		case 'N': display = 0b00101010; break;
		case 'O': display = 0b00111010; break;
		case 'P': display = 0b11001110; break;
		case 'Q': display = 0b11111100; break;
		case 'R': display = 0b00001010; break;
		case 'S': display = 0b10110110; break;
		case 'T': display = 0b00011110; break;
		case 'U': display = 0b01111100; break;
		case 'V': display = 0b01111100; break;
		case 'X': display = 0b01101110; break;
		case 'W': display = 0b01111100; break;
		case 'Y': display = 0b01110110; break;
		case 'Z': display = 0b11011010; break;

		case '+': display = 0b01100010; break;
		case '-': display = 0b00000010; break;
	}

	return display;
}
/*==============================================================================
SEPARA OS DIGITOS
==============================================================================*/
void displaySeparaDigitos() {
	displaysCronometro[0] = cronometro.decimais;
	displaysCronometro[1] = cronometro.segundos % 10;
	displaysCronometro[2] = cronometro.segundos / 10;
	displaysCronometro[3] = cronometro.minutos % 10;
	displaysCronometro[4] = cronometro.minutos / 10;

	displaysEquipeA[0] = periodo;
	displaysEquipeA[1] = faltasEquipeA;
	displaysEquipeA[2] = pontosEquipeA % 10;
	displaysEquipeA[3] = pontosEquipeA / 10;
	displaysEquipeA[3] %= 10;
	displaysEquipeA[4] = pontosEquipeA / 100;

	displaysEquipeB[0] = faltasEquipeB;
	displaysEquipeB[1] = pontosEquipeB % 10;
	displaysEquipeB[2] = pontosEquipeB / 10;
	displaysEquipeB[2] %= 10;
	displaysEquipeB[3] = pontosEquipeB / 100;
	displaysEquipeB[4] = 0; //não utilizado
}
/*==============================================================================
ATUALIZA DISPLAY
==============================================================================*/
void atualizaDisplays() {
	static uint8_t valorDisplayCronometro = 0, valorDisplayEquipeA = 0, valorDisplayEquipeB = 0;
	static uint8_t controleFuncao = 0, bit = 0, numero = 0;

	on(DISPLAY1_ENABLE_GPIO_Port, DISPLAY1_ENABLE_Pin);
	on(DISPLAY1_ST_GPIO_Port, DISPLAY1_ST_Pin);

	on(DISPLAY2_ENABLE_GPIO_Port, DISPLAY2_ENABLE_Pin);
	on(DISPLAY2_ST_GPIO_Port, DISPLAY2_ST_Pin);

	on(DISPLAY3_ENABLE_GPIO_Port, DISPLAY3_ENABLE_Pin);
	on(DISPLAY3_ST_GPIO_Port, DISPLAY3_ST_Pin);


	switch(controleFuncao) {
		case 0:
			displaySeparaDigitos();
			controleFuncao ++;
			break;

		case 1:
			valorDisplayCronometro = desenhaNumero(displaysCronometro[numero]);
			valorDisplayEquipeA = desenhaNumero(displaysEquipeA[numero]);
			valorDisplayEquipeB = desenhaNumero(displaysEquipeB[numero]);
			controleFuncao ++;
			bit = 0;
			break;

		case 2:
			on(DISPLAY2_CLOCK_GPIO_Port, DISPLAY2_CLOCK_Pin);
			on(DISPLAY3_CLOCK_GPIO_Port, DISPLAY3_CLOCK_Pin);
			if(numero < 4) {
				on(DISPLAY1_CLOCK_GPIO_Port, DISPLAY1_CLOCK_Pin);
				setPin(DISPLAY1_DATA_GPIO_Port, DISPLAY1_DATA_Pin, bitRead(valorDisplayEquipeB, bit));
			}
			setPin(DISPLAY2_DATA_GPIO_Port, DISPLAY2_DATA_Pin, bitRead(valorDisplayCronometro, bit));
			setPin(DISPLAY3_DATA_GPIO_Port, DISPLAY3_DATA_Pin, bitRead(valorDisplayEquipeA, bit));
			controleFuncao ++;
			break;

		case 3:
			off(DISPLAY1_CLOCK_GPIO_Port, DISPLAY1_CLOCK_Pin);
			off(DISPLAY2_CLOCK_GPIO_Port, DISPLAY2_CLOCK_Pin);
			off(DISPLAY3_CLOCK_GPIO_Port, DISPLAY3_CLOCK_Pin);
			controleFuncao = 2;

			bit ++;
			if(bit >= 8) {
				bit = 0;
				controleFuncao = 4;
			}
			break;

		case 4:
			off(DISPLAY1_DATA_GPIO_Port, DISPLAY1_DATA_Pin);
			off(DISPLAY2_DATA_GPIO_Port, DISPLAY2_DATA_Pin);
			off(DISPLAY3_DATA_GPIO_Port, DISPLAY3_DATA_Pin);
			controleFuncao ++;
			break;

		default:
			controleFuncao ++;
			if(controleFuncao >= 30) {
				controleFuncao = 0;
				numero ++;
				if(numero >= 5) {
					numero = 0;
				}
			}
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
