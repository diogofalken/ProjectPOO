#include "pch.h"
#include "FTipo2.h"


FTipo2::FTipo2(int numero, int _x_pos, int _y_pos) : Fronteira(numero, _x_pos, _y_pos) {
	peso_transportado = 0;
}

//-------------------------------------------------------------------
//Método: PassarPelaFronteira
//Parametros:
// Entrada:
//
// Retorno:
//   
//-------------------------------------------------------------------
void FTipo2::PassarPelaFronteira() {
	peso_transportado++;
}

void FTipo2::Mostrar() {
	Fronteira::Mostrar();
	cout << "Peso Transportado: " << peso_transportado << endl;
}

int FTipo2::getTipo() {
	return 3;
}

FTipo2::~FTipo2() {

}

