#pragma once
#include "pch.h"

class Uteis {

public:
	Uteis();
	~Uteis();
	
	/*
	 * @brief: Verificar se o ficheiro esta aberto
	 * @param: file
	 * @return: Return true se abriu corretamente ou false se houve falha a abrir o ficheiro
	*/
	static bool FicheiroAberto(ifstream *file) {
		if (file)
			return true;
		return false;
	}
};

