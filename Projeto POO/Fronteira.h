#pragma once
#include "pch.h"

class Fronteira {
private:
	int vertice;
	int x_pos;
	int y_pos;
	int tipo;
	int visitas;
public:
	Fronteira(int numero, int _x_pos, int _y_pos);

	// Mostrar info das Fronteiras
	virtual void Mostrar();

	// Devolve o valor do vertice
	virtual int getVertice();

	// Devolve o tipo de fronteira
	virtual int getTipo();

	// Devolve a posicao x
	virtual int getX_pos();

	// Devolve a posicao y
	virtual int getY_pos();
	
	// Altera o valor do vertice
	void setVertice(int numero);

	// Aumenta 1 visita na fronteira
	void visitouFronteira();

	~Fronteira();
};

