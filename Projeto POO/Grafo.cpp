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
	ifstream file_graph(fich_grafo);

	// Variaveis auxiliares
	string buffer;
	string current;
	char *x = new char[128];
	unsigned int i, number, fronteira_tipo, index = 0;

	// Verificar se o ficheiro foi aberto corretamente  
	if (!Uteis::FicheiroAberto(&file_graph)) {
		cout << "Nao foi possivel abrir o ficheiro " << fich_grafo << endl;
		exit(1);
	}

	// Retirar os vertices
	getline(file_graph, buffer);
	n_vertices = atoi(buffer.c_str());

	// Retirar as arestas
	getline(file_graph, buffer);
	n_arestas = atoi(buffer.c_str());

	Fronteira *current;

	// Retirar a info dos vertices
	// TODO: ACABAR ESTA FUNCAO
	while (!file_graph.eof()) {
		getline(file_graph, buffer);
		stringstream ss(buffer);
		i = 0;
		while (getline(ss, buffer, ';')) {
			if (buffer != DELIMITADOR_FICHEIRO) {
				if (i = 0) {
					ss << number;
				}
				if (i = 3) {
					ss << fronteira_tipo;
				}
				i++;
			}
			break;
		}
	}

	file_graph.close();
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
