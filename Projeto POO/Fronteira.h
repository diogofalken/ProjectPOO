#pragma once
#include "pch.h"

class Fronteira {
private:
	unsigned int vertice;
public:
	Fronteira();

	// Mostrar info das Fronteiras
	virtual void Mostrar();

	// Devolve o valor do vertice
	int getVertice();

	~Fronteira();
};

