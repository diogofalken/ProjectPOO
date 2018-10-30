#pragma once
#include "Fronteira.h"

class FTipo1 : public Fronteira {
private:
	unsigned int preco_pago;

public:
	FTipo1(int vertice);
	void Mostrar();
	~FTipo1();
};

