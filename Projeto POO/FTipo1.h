#pragma once
#include "Fronteira.h"

class FTipo1 : public Fronteira {
private:
	unsigned int preco_pago;
public:
	FTipo1(int numero, int _x_pos, int _y_pos);
	void Mostrar();
	~FTipo1();
};

