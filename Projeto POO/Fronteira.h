#pragma once
#include "pch.h"

class Fronteira {
private:
	unsigned int vertice;
	unsigned int x_pos;
	unsigned int y_pos;
	unsigned int tipo;
public:
	Fronteira(int numero, int _x_pos, int _y_pos);

	// Mostrar info das Fronteiras
	virtual void Mostrar();

	// Devolve o valor do vertice
	int getVertice();

	// Devolve o tipo de fronteira
	int getTipo();
	// Altera o valor do vertice
	void setVertice(int numero);

	~Fronteira();
};

