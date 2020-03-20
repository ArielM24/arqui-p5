using namespace std;

class archivoRegistros {
public:
	unsigned short writeData;
	unsigned char writeReg;
	unsigned char readReg1;
	unsigned char readReg2;
	unsigned char shamt;
	bool WR;
	bool SHE;
	bool DIR;
	bool CLR;
	unsigned short readData1;
	unsigned short readData2;
	int Banco[16];
	
	~archivoRegistros();
	archivoRegistros();
	void set();
	void get();
	void operacionSincrona(unsigned short writeData, unsigned char writeReg,
	 unsigned char shamt, bool WR, bool SHE, bool DIR, bool CLR);
	void operacionAsincrona(bool CLR);
	void operacionAsincrona(bool CLR, 
		unsigned char readReg1, unsigned char readReg2);
private:
	void clr();
};
