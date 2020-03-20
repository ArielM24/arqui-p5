#include "registros.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cstdio>

using namespace std;

archivoRegistros::archivoRegistros(){
	writeData = 0;
	writeReg = 0;
	readReg1 = 0;
	readReg2 = 0;
	shamt = 0;
	WR = false;
	SHE = false;
	DIR = false;
	CLR = false;
	readData1 = 0;
	readData2 = 0;
}

archivoRegistros::~archivoRegistros(){
}

void archivoRegistros::set(){
	for(char i = 0; i < 16; i++) {
		Banco[i] = rand();
	}
}

void archivoRegistros::get(){
	printf("Banco\n");
	for(char i = 0; i < 16; i++) {
		printf("-------------------------\n");
		printf("%2d :%16d\n",i, Banco[i]);
	}	
	printf("\n");
}

void archivoRegistros::clr(){
	for(char i = 0; i < 16; i++) {
		Banco[i] = 0;
	}
}

void archivoRegistros::operacionSincrona(unsigned short writeData, unsigned char writeReg,
	 unsigned char shamt, bool WR, bool SHE, bool DIR, bool CLR){
	if(CLR){
		clr();
	}else if(WR){
		if(SHE){
			if(DIR){
				Banco[writeReg] = Banco[readReg1] << shamt;
			}else{
				Banco[writeReg] = Banco[readReg1] >> shamt;
			}
		}else{
			Banco[writeReg] = writeData;
		}
	}
}

void archivoRegistros::operacionAsincrona(bool CLR){
	clr();
}

void archivoRegistros::operacionAsincrona(bool CLR, 
		unsigned char readReg1, unsigned char readReg2){
	if(CLR){
		clr();
	}else{
		readData1 = Banco[readReg1];
		readData2 = Banco[readReg2];
		printf("readData1: %d\n",readData1);
		printf("readData2: %d\n",readData2);
	}
}