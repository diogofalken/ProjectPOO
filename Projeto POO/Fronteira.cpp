#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira() {

}

//-------------------------------------------------------------------
//M�todo: Mostrar
//Parametros:
// Entrada:
// Retorno:
//-------------------------------------------------------------------
void Fronteira::Mostrar() {
	cout << "V�rtice: " << vertice << endl;
}

//-------------------------------------------------------------------
//M�todo: Adjancencia
//Parametros:
// Entrada:
// Retorno:
//    numero do vertice
//-------------------------------------------------------------------
int Fronteira::getVertice() {
	return vertice;
}

Fronteira::~Fronteira() {

}
