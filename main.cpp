#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "registros.h"

using namespace std;

int main(void){
	srand(time(NULL));
	archivoRegistros r = archivoRegistros();

	//1.- Reset
	r.operacionAsincrona(true);
	r.get();
	getchar();

	//2.- Banco[1] = 89
	r.operacionSincrona(89,1,0,0,true,false,false,false);
	r.get();
	getchar();

	//3.- Banco[2] = 72
	r.operacionSincrona(72,2,0,0,true,false,false,false);
	r.get();
	getchar();

	//4.- Banco[3] = 123
	r.operacionSincrona(123,3,0,0,true,false,false,false);
	r.get();
	getchar();

	//5.- Banco[4] = 53
	r.operacionSincrona(53,4,0,0,true,false,false,false);
	r.get();
	getchar();	

	//6.- Leer Banco[1] y Banco[2]
	r.operacionAsincrona(false,1,2);
	getchar();

	//7.- Leer Banco[3] y Banco[4]
	r.operacionAsincrona(false,3,4);
	getchar();

	//8.- Banco[2] = Banco[1] << 3
	r.operacionSincrona(0,2,1,3,true,true,true,false);
	r.get();
	getchar();

	//9.- Banco[4] = Banco[3] >> 5
	r.operacionSincrona(0,4,3,5,true,true,false,false);
	r.get();
	getchar();

	//10.- Leer Banco[1] y Banco[2]
	r.operacionAsincrona(false,1,2);
	getchar();

	//11.- Leer Banco[3] y Banco[4]
	r.operacionAsincrona(false,3,4);
	getchar();

	//12.- get
	r.get();
	getchar();

	//1.- Reset
	r.operacionAsincrona(true);
	r.get();
	getchar();
	return 0;
}