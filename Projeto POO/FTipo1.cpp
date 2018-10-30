#include "pch.h"
#include "FTipo1.h"


FTipo1::FTipo1(int vertice) : Fronteira(vertice){

}

void FTipo1::Mostrar() {
	Fronteira::Mostrar();
	cout << "Pago: " << preco_pago << endl;
}

FTipo1::~FTipo1() {

}
