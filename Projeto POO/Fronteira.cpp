#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira(int numero) {
	vertice = numero;
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

void Fronteira::setVertice(int numero) {
	vertice = numero;
}

Fronteira::~Fronteira() {

}
