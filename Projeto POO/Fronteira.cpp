#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira(int numero, int _x_pos, int _y_pos) {
	vertice = numero;
	x_pos = _x_pos;
	y_pos = _y_pos;
}

//-------------------------------------------------------------------
//M�todo: Mostrar
//Parametros:
// Entrada:
// Retorno:
//-------------------------------------------------------------------
void Fronteira::Mostrar() {
	cout << "Vertice: " << vertice << endl;
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
