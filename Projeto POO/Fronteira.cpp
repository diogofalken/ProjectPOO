#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira(int numero) {
	vertice = numero;
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

void Fronteira::setVertice(int numero) {
	vertice = numero;
}

Fronteira::~Fronteira() {

}
