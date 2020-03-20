#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include "registros.h"

using namespace std;

int main(void){
	srand(time(NULL));
	archivoRegistros r = archivoRegistros();
	r.operacionAsincrona(true);
	r.get();
	getchar();

	r.operacionSincrona(89,1,0,true,false,false,false);
	r.get();
	getchar();

	r.operacionSincrona(72,2,0,true,false,false,false);
	r.get();
	getchar();

	r.operacionSincrona(123,3,0,true,false,false,false);
	r.get();
	getchar();

	r.operacionSincrona(53,4,0,true,false,false,false);
	r.get();
	getchar();	

	r.operacionAsincrona(false,1,2);
	getchar();

	r.operacionAsincrona(false,3,4);
	getchar();

	r.operacionSincrona(0,2,0,true,false,false,false);
	r.get();
	getchar();
	return 0;
}