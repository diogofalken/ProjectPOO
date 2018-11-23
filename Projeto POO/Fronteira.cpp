#include "pch.h"
#include "Fronteira.h"


Fronteira::Fronteira(int numero, int _x_pos, int _y_pos) {
	vertice = numero;
	x_pos = _x_pos;
	y_pos = _y_pos;
	tipo = 0;
	visitas = 0;
}

//-------------------------------------------------------------------
//Método: Mostrar
//Parametros:
// Entrada:
// Retorno:
//-------------------------------------------------------------------
void Fronteira::Mostrar() {
	cout << "Vertice: " << vertice << endl;
}

//-------------------------------------------------------------------
//Método: getVertice
//Parametros:
// Entrada:
// Retorno:
//    numero do vertice
//-------------------------------------------------------------------
int Fronteira::getVertice() {
	return vertice;
}

//-------------------------------------------------------------------
//Método: getTipo
//Parametros:
// Entrada:
// Retorno:
//    Tipo de fronteira (Oficial, T1, T2)
//-------------------------------------------------------------------
int Fronteira::getTipo() {
	return tipo;
}

//-------------------------------------------------------------------
//Método: setVertice
//Parametros:
// Entrada:
// Retorno:
//
//-------------------------------------------------------------------
void Fronteira::setVertice(int numero) {
	vertice = numero;
}

void Fronteira::visitouFronteira() {
	visitas++;
}

// Devolve a posicao x
int Fronteira::getX_pos() {
	return x_pos;
}

// Devolve a posicao y
int Fronteira::getY_pos() {
	return y_pos;
}

Fronteira::~Fronteira() {

}
