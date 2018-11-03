#pragma once
#include "Fronteira.h"

class FTipo2 : public Fronteira {
private:
	unsigned int peso_transportado;
public:
	// Construtor
	FTipo2(int numero, int _x_pos, int _y_pos);
	
	// Destrutor
	~FTipo2();
	
	// Aumentar 1kg sempre que passa por uma fronteira do tipo 2
	void PassarPelaFronteira();

	// Mostrar peso_transportado
	void Mostrar();
};

