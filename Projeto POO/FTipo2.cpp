#include "pch.h"
#include "FTipo2.h"


FTipo2::FTipo2() {
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

FTipo2::~FTipo2() {

}

