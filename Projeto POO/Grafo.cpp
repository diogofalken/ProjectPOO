#include "pch.h"
#include "Grafo.h"
#include "Uteis.h"


#define DELIMITADOR_FICHEIRO "//-------------------"

//-------------------------------------------------------------------
//Método: Grafo
//Parametros:
// Entrada:
//
// Retorno:
//
//-------------------------------------------------------------------
Grafo::Grafo() {

}

//-------------------------------------------------------------------
//Método: Load
//Parametros:
// Entrada:
//     fich_grafo: Ficheiro dos dados do Grafo
//     fich_pessoas: Ficheiro das pessoas que querem fazer as viagens entre as fronteiras
// Retorno:
//    true/false, mediante a leitura correcta!
//-------------------------------------------------------------------
bool Grafo::Load(const string &fich_grafo, const string &fich_pessoas) {
	// Abrir o ficheiro
	ifstream in_file(fich_grafo);

	// Variaveis auxiliares
	string buffer, aux_buffer;
	int x, y, vertice, tipo, parametro = 0, index = 0;

	// Verificar se o ficheiro foi aberto corretamente  
	if (!Uteis::FicheiroAberto(&in_file)) {
		cout << "Nao foi possivel abrir o ficheiro " << fich_grafo << endl;
		return false;
	}

	// Retirar os vertices
	getline(in_file, buffer);
	n_vertices = atoi(buffer.c_str());

	// Retirar as arestas
	getline(in_file, buffer);
	n_arestas = atoi(buffer.c_str());

	while (!in_file.eof()) {
		getline(in_file, buffer);
		aux_buffer = buffer;
		stringstream ss(buffer);
		parametro = 0;
		
		// Se a string for igual ao Delimitador de Arestas/Vertices parar
		if (aux_buffer == DELIMITADOR_FICHEIRO) {
			break;
		}

		while (getline(ss, buffer, ';')) {
			stringstream aux(buffer);
			if (parametro == 0) {
				aux >> vertice;
			}
			if (parametro == 1) {
				aux >> x;
			}
			if (parametro == 2) {
				aux >> y;
			}
			if (parametro == 3) {
				aux >> tipo;
			}
			parametro++;
		}
		Fronteira current = fronteira_vertice_principal(vertice, x, y, tipo);
		lista_fronteiras.push_back(current);
	}
	for (list<Fronteira>::iterator it = lista_fronteiras.begin(); it != lista_fronteiras.end(); it++) {
		(*it).Mostrar();
	}
	/*
	int vertice_origem, vertice_destino, _custo;
	while (!in_file.eof()) {
		getline(in_file, buffer);
		aux_buffer = buffer;
		stringstream ss(buffer);
		parametro = 0;

		while (getline(ss, buffer, ';')) {
			stringstream aux(buffer);
			if (parametro == 0) {
				aux >> vertice_origem;
			}
			if (parametro == 1) {
				aux >> vertice_destino;
			}
			if (parametro == 2) {
				aux >> _custo;
			}
			parametro++;
		}
		Fronteira_vizinha aux;
		aux.custo = _custo;
		aux.vertice = myGrafo[vertice_destino].cbegin();
		myGrafo[vertice_origem];
	}*/

	cout << "Vertices: " << n_vertices << " Arestas: " << n_arestas << endl;
	return NULL;
}

//-------------------------------------------------------------------
//Método: ContarNos
//Parametros:
// Entrada:
//
// Retorno:
//    Numero de nos do grafo
//-------------------------------------------------------------------
int Grafo::ContarNos() {
	return NULL;
}

//-------------------------------------------------------------------
//Método: ContarArcos
//Parametros:
// Entrada:
//
// Retorno:
//    Numero de arcos/arestas do grafo
//-------------------------------------------------------------------
int Grafo::ContarArcos() {
	return -1;
}

//-------------------------------------------------------------------
//Método: Memoria
//Parametros:
// Entrada:
//
// Retorno:
//    Quanta memoria está a ser ocupada pelo grafo
//-------------------------------------------------------------------
int Grafo::Memoria() {
	return -1;
}

//-------------------------------------------------------------------
//Método: NoMaisArcos
//Parametros:
// Entrada:
//
// Retorno:
//    No/fronteira com mais arcos ( se for mais que um da return numa lista)
//-------------------------------------------------------------------
list<int> *Grafo::NoMaisArcos() {
	return NULL;
}

//-------------------------------------------------------------------
//Método: Adjancencia
//Parametros:
// Entrada:
//     v1: vertice 1
//     v2: vertice 2
// Retorno:
//    true/false, mediante serem adjacentes ou nao
//-------------------------------------------------------------------
bool Grafo::Adjacencia(int v1, int v2) {
	return false;
}

//-------------------------------------------------------------------
//Método: Caminho
//Parametros:
// Entrada:
//     v1: vertice 1
//     v2: vertice 2
//	   custo_total: custo total entre o vertice 1 e o vertice 2
// Retorno:
//    caminho entre o vertice 1 e o vertice 2
//-------------------------------------------------------------------
list<int> *Grafo::Caminho(int v1, int v2, double &custo_total) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: VerticesIsolados
//Parametros:
// Entrada:
//
// Retorno:
//    Lista de vertices isolados
//-------------------------------------------------------------------
list<int> *Grafo::VerticesIsolados() {
	return NULL;
}

//-------------------------------------------------------------------
//Método: Search
//Parametros:
// Entrada:
//     v: vertice a procurar
// Retorno:
//    true/false, dependendo se encontra ou nao o vertice
//-------------------------------------------------------------------
bool Grafo::Search(int v) {
	return false;
}

//-------------------------------------------------------------------
//Método: RemoverVertice
//Parametros:
// Entrada:
//	   v: vertice a procurar 
// Retorno:
//    true/false, dependendo se o vertice foi removido ou nao
//-------------------------------------------------------------------
bool Grafo::RemoverVertice(int v) {
	return false;
}

//-------------------------------------------------------------------
//Método: RemoverAresta
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
// Retorno:
//    true/false, dependendo se o aresta foi removida ou nao
//-------------------------------------------------------------------
bool Grafo::RemoverAresta(int v1, int v2) {
	return false;
}

//-------------------------------------------------------------------
//Método: EscreverXML
//Parametros:
// Entrada:
//	   s: Nome do ficheiro que se quer gravar as informacoes do grafo
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::EscreverXML(const string &s) {

}

//-------------------------------------------------------------------
//Método: LerXML
//Parametros:
// Entrada:
//	   s: Nome do ficheiro que se quer ler as informacoes do grafo
// Retorno:
//    true/false, dependendo se o ficheiro foi lido ou nao
//-------------------------------------------------------------------
bool Grafo::LerXML(const string &s) {
	return false;
}

//-------------------------------------------------------------------
//Método: DevolveVerticesTipo
//Parametros:
// Entrada:
//	   tipo: tipo de vertice pretendido
// Retorno:
//    lista com os vertices do grafo do tipo pretendido
//-------------------------------------------------------------------
list<int> *Grafo::DevolveVerticesTipo(const string &tipo) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: CaminhoMinimo
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   custo_total: custo total entre os dois vertices
// Retorno:
//    lista dos vertices com o caminho mais curto entre v1 e v2
//-------------------------------------------------------------------
list<int> *Grafo::CaminhoMinimo(int v1, int v2, double &custo_total) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: CaminhoMaximo
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   custo_total: custo total entre os dois vertices
// Retorno:
//    lista dos vertices com o caminho maximo entre v1 e v2
//-------------------------------------------------------------------
list<int> *Grafo::CaminhoMaximo(int v1, int v2, double &custo_total) {
	return NULL;
}

//-------------------------------------------------------------------
//Método: PossivelCaminho
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   v2: vertice 2
//	   TipoFronteira: tipo de uma fronteira
// Retorno:
//    true/falso, dependendo se existe caminho entre v1 e v2 por fronteiras do TipoFronteira
//-------------------------------------------------------------------
bool Grafo::PossivelCaminho(int v1, int v2, int TipoFronteira) {
	return false;
}

//-------------------------------------------------------------------
//Método: FronteirasMenosVisitadas
//Parametros:
// Entrada:
//	   Lv: Lista de viagens
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::FronteirasMenosVisitadas(list<int> &Lv) {

}

//-------------------------------------------------------------------
//Método: SitiosInacessiveisAPartirDe
//Parametros:
// Entrada:
//	   v1: vertice 1
//	   Lv: Lista de viagens
// Retorno:
//
//-------------------------------------------------------------------
void Grafo::SitiosInacessiveisAPartirDe(int V1, list<int> &Lv) {

}

//-------------------------------------------------------------------
//Método: ~Grafo
//Parametros:
// Entrada:
//
// Retorno:
//
//-------------------------------------------------------------------
Grafo::~Grafo() {

}
