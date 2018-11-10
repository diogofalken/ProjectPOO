#include "pch.h"
#include "Arestas.h"


Arestas::Arestas() {
	custo = 0;
	vertice = NULL;
}

void Arestas::Mostrar() {
	vertice->Mostrar();
	cout << "Custo: " << custo << endl;
}

void Arestas::setCusto(unsigned int _custo) {
	custo = _custo;
}

void Arestas::setVertice(Fronteira *novo_vertice) {
	vertice = novo_vertice;
}

Fronteira* Arestas::getVertice() {
	return vertice;
}

int Arestas::getCusto() {
	return custo;
}

Arestas::~Arestas(){
	delete(vertice);
}
