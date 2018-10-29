#pragma once
#include "pch.h"

class Fronteira {
private:
	unsigned int vertice;
public:
	Fronteira(int numero);

	// Mostrar info das Fronteiras
	virtual void Mostrar();

	// Devolve o valor do vertice
	int getVertice();

	// Altera o valor do vertice
	void setVertice(int numero);

	~Fronteira();
};

