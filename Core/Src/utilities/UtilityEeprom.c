///////////////////////////////////////////////////////////////////////////////
//ARQUIVO:    UtilityEeprom
//AUTOR:      Fábio Almeida
//CRIADO:     03/01/2024
//OBSERVAÇÕES:
////////////////////////////////////////////////////////////////////////////////
#include "main.h"
#include "global.h"
/*==============================================================================
CONSTANTES
==============================================================================*/
enum TIPO_MEMORIA {
	MEMORIA_24LC256, //serve também para o 512
	MEMORIA_24LC08
};

#define	EEPROM_ADDR_0	0x50
#define EEPROM_ADDR_1   0x51
#define EEPROM_ADDR_2   0x52
#define EEPROM_ADDR_3   0x53
#define EEPROM_ADDR_4   0x54
#define EEPROM_ADDR_5   0x55
#define EEPROM_ADDR_6   0x56
#define EEPROM_ADDR_7   0x57

#define	EEPROM_INICIALIZADA		0x0A
const uint8_t MEMORIA = MEMORIA_24LC256;
/*==============================================================================
WRITE EXTERNAL EEPROM
==============================================================================*/
void writeExternalEeprom(uint8_t device, uint16_t address, uint8_t data) {
	uint8_t pData[3];
	uint8_t deviceHex = 0x00;
	uint8_t quantidadeDados = 0;
	if(MEMORIA == MEMORIA_24LC256) {
		pData[0] = make8(address, 1);
		pData[1] = make8(address, 0);
		pData[2] = data;
		quantidadeDados = 3;

		switch(device) {
			case 0:	deviceHex = EEPROM_ADDR_0; break;
			case 1:	deviceHex = EEPROM_ADDR_1; break;
			case 2:	deviceHex = EEPROM_ADDR_2; break;
			case 3:	deviceHex = EEPROM_ADDR_3; break;
			case 4:	deviceHex = EEPROM_ADDR_4; break;
			case 5:	deviceHex = EEPROM_ADDR_5; break;
			case 6:	deviceHex = EEPROM_ADDR_6; break;
			case 7:	deviceHex = EEPROM_ADDR_7; break;
			default: return;
		}
	}
	else if(MEMORIA == MEMORIA_24LC08) {
		uint8_t blocoMemoria = 0;
		if(device > 0) { //somente 1 é possivel ter no barramento
			return;
		}
		for(; address > 255; address -= 255) {
			blocoMemoria ++;
		}
		pData[0] = address;
		pData[1] = data;
		quantidadeDados = 2;

		switch(blocoMemoria) {
			case 0:	deviceHex = EEPROM_ADDR_0; break;
			case 1:	deviceHex = EEPROM_ADDR_1; break;
			case 2:	deviceHex = EEPROM_ADDR_2; break;
			case 3:	deviceHex = EEPROM_ADDR_3; break;
			default: return;
		}
	}


	deviceHex <<= 1;

	HAL_I2C_Master_Transmit(&hi2c1, deviceHex, &pData, quantidadeDados, 100);
	HAL_Delay(10);
}
/*==============================================================================
READ EXTERNAL EEPROM
==============================================================================*/
uint8_t readExternalEeprom(uint8_t device, uint16_t address) {
	uint8_t data = 0;
	uint8_t pData[2];
	uint8_t deviceHex = 0x00;
	uint8_t quantidadeDados = 0;

	if(MEMORIA == MEMORIA_24LC256) {
		pData[0] = make8(address, 1);
		pData[1] = make8(address, 0);
		quantidadeDados = 2;

		switch(device) {
			case 0:	deviceHex = EEPROM_ADDR_0; break;
			case 1:	deviceHex = EEPROM_ADDR_1; break;
			case 2:	deviceHex = EEPROM_ADDR_2; break;
			case 3:	deviceHex = EEPROM_ADDR_3; break;
			case 4:	deviceHex = EEPROM_ADDR_4; break;
			case 5:	deviceHex = EEPROM_ADDR_5; break;
			case 6:	deviceHex = EEPROM_ADDR_6; break;
			case 7:	deviceHex = EEPROM_ADDR_7; break;
			default: return;
		}
	}
	else if(MEMORIA == MEMORIA_24LC08) {
		uint8_t blocoMemoria = 0;
		if(device > 0) { //somente 1 é possivel ter no barramento
			return;
		}
		for(; address > 255; address -= 255) {
			blocoMemoria ++;
		}
		pData[0] = address;
		quantidadeDados = 1;

		switch(blocoMemoria) {
			case 0:	deviceHex = EEPROM_ADDR_0; break;
			case 1:	deviceHex = EEPROM_ADDR_1; break;
			case 2:	deviceHex = EEPROM_ADDR_2; break;
			case 3:	deviceHex = EEPROM_ADDR_3; break;
			default: return;
		}
	}

	deviceHex <<= 1;

	HAL_I2C_Master_Transmit(&hi2c1, deviceHex, &pData, quantidadeDados, 100);
	HAL_Delay(10);
	deviceHex ++;
	HAL_I2C_Master_Receive(&hi2c1, deviceHex, &data, 1, 100);
	HAL_Delay(10);

	return data;
}
/*==============================================================================
SALVA CRONOMETRO
==============================================================================*/
void salvaCronometro() {
	writeExternalEeprom(0, 8, cronometro.minutos);
	writeExternalEeprom(0, 9, cronometro.segundos);
	writeExternalEeprom(0, 10, cronometro.decimais);
}
/*==============================================================================
SALVA SETPOINT CRONOMETRO
==============================================================================*/
void salvaSetpointCronometro() {
	writeExternalEeprom(0, 11, setpointCronometro.minutos);
	writeExternalEeprom(0, 12, setpointCronometro.segundos);
	writeExternalEeprom(0, 13, setpointCronometro.decimais);
	writeExternalEeprom(0, 14, tipoCronometro);
}
/*==============================================================================
SALVA DADOS PLACAR
==============================================================================*/
void salvaDadosPlacar() {
	writeExternalEeprom(0, 1, make8(pontosEquipeA, 1));
	writeExternalEeprom(0, 2, make8(pontosEquipeA, 0));
	writeExternalEeprom(0, 3, make8(pontosEquipeB, 1));
	writeExternalEeprom(0, 4, make8(pontosEquipeB, 0));

	writeExternalEeprom(0, 5, faltasEquipeA);
	writeExternalEeprom(0, 6, faltasEquipeB);
	writeExternalEeprom(0, 7, periodo);
}
/*==============================================================================
WRITE ALL EEPROM
==============================================================================*/
void writeAllEeprom() {
	salvaCronometro();
	salvaSetpointCronometro();
	salvaDadosPlacar();
}
/*==============================================================================
READ EEPROM
==============================================================================*/
void readEeprom() {
	if(HAL_I2C_IsDeviceReady(&hi2c1, EEPROM_ADDR_0 + 1, 10, 100)) {
		pontosEquipeA = make16(readExternalEeprom(0, 1), readExternalEeprom(0, 2));
		pontosEquipeB = make16(readExternalEeprom(0, 3), readExternalEeprom(0, 4));

		faltasEquipeA = readExternalEeprom(0, 5);
		faltasEquipeB = readExternalEeprom(0, 6);
		periodo = readExternalEeprom(0, 7);

		cronometro.minutos = readExternalEeprom(0, 8);
		cronometro.segundos = readExternalEeprom(0, 9);
		cronometro.decimais = readExternalEeprom(0, 10);

		setpointCronometro.minutos = readExternalEeprom(0, 11);
		setpointCronometro.segundos = readExternalEeprom(0, 12);
		setpointCronometro.decimais = readExternalEeprom(0, 13);

		tipoCronometro = readExternalEeprom(0, 14);
	}
}
/*==============================================================================
APAGA EEPROM
==============================================================================*/
void apagaEeprom() {
	if(HAL_I2C_IsDeviceReady(&hi2c1, EEPROM_ADDR_0 + 1, 10, 100)) {
		writeExternalEeprom(0, 0, EEPROM_INICIALIZADA);

		pontosEquipeA = 0;
		pontosEquipeB = 0;
		faltasEquipeA = 0;
		faltasEquipeB = 0;
		periodo = 1;

		tipoCronometro = REGRESSIVO;

		cronometro.minutos = 20;
		cronometro.segundos = 0;
		cronometro.decimais = 0;

		setpointCronometro.minutos = 20;
		setpointCronometro.segundos = 0;
		setpointCronometro.decimais = 0;

		writeAllEeprom();
	}
}
/*==============================================================================
VERIFICA EEPROM
==============================================================================*/
void verificaEeprom() {
	if(HAL_I2C_IsDeviceReady(&hi2c1, EEPROM_ADDR_0 + 1, 10, 100)) {
		if(readExternalEeprom(0, 0) != EEPROM_INICIALIZADA) {
			apagaEeprom();
		}
	}
}
/*==============================================================================
FIM DO ARQUIVO
==============================================================================*/
