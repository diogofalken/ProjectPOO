#include "pch.h"
#include "FTipo1.h"


FTipo1::FTipo1(int numero, int _x_pos, int _y_pos) : Fronteira(numero, _x_pos, _y_pos){
	preco_pago = 0;
}

void FTipo1::Mostrar() {
	Fronteira::Mostrar();
	cout << "Pago: " << preco_pago << endl;
}

FTipo1::~FTipo1() {

}
