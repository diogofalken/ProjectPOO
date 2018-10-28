#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira() {

}

//-------------------------------------------------------------------
//Método: Mostrar
//Parametros:
// Entrada:
// Retorno:
//-------------------------------------------------------------------
void Fronteira::Mostrar() {
	cout << "Vértice: " << vertice << endl;
}

//-------------------------------------------------------------------
//Método: Adjancencia
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
