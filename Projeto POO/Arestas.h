#pragma once
#include "Fronteira.h"

class Arestas {
private:
	Fronteira *vertice;
	unsigned int custo;
public:
	Arestas();
	void Mostrar();
	void setCusto(unsigned int _custo);
	void setVertice(Fronteira *novo_vertice);
	Fronteira* getVertice();
	int getCusto();
	~Arestas();
};

