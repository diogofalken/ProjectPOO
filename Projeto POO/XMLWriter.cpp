#include "pch.h"
#include "XMLWriter.h"
using namespace std;


XMLWriter::XMLWriter() {
	int indent = 0;
	int openTags = 0;
	int openElements = 0;
}

bool XMLWriter::escreverPrincipioPrograma(string file_name) {
	out_file.open(file_name);
	if (out_file.is_open()) {
		cout << "Ficheiro foi criado com sucesso." << endl;
		out_file << "<!--XML Document-->\n";
		out_file << "<?xml version='1.0' encoding='UTF-8'>\n";
		return true;
	}
	cout << "O Ficheiro nao foi criado." << endl;
	return false;
}

void XMLWriter::escreverElementoString(string element, string value) {
	if (out_file.is_open()) {
		for (int i = 0; i < indent + 1; i++) {
			out_file << "\t";
		}
		out_file << "<" << value << ">" << element << "<\\" << value << ">" << endl;
	}
	else {
		cout << "Ficheiro fechado. Incapacitado de escrever para o ficheiro." << endl;
	}
}

void XMLWriter::escreverPrincipioElemento(string element) {
	if (out_file.is_open()) {
		for (int i = 0; i < indent; i++) {
			out_file << "\t";
		}
		tempElementTag.resize(openElements + 1);
		tempElementTag[openElements] = element;
		openElements += 1;
		out_file << "<" << element << ">" << endl;
	}
	else {
		cout << "Ficheiro fechado. Incapacitado de escrever para o ficheiro." << endl;
	}
}

void XMLWriter::escreverFimElemento() {
	if (out_file.is_open()) {
		for (int i = 0; i < indent; i++) {
			out_file << "\t";
		}
		out_file << "</" << tempElementTag[openElements - 1] << ">\n";
		tempElementTag.resize(openElements - 1);
		openElements -= 1;
	}
	else {
		cout << "Ficheiro fechado. Incapacitado de escrever para o ficheiro." << endl;
	}
}

void  XMLWriter::escreverPrincipioTag(string tag) {
	if (out_file.is_open()) {
		tempOpenTag.resize(openTags + 1);
		out_file << "<" << tag << ">\n";
		tempOpenTag[openTags] = tag;
		indent += 1;
		openTags += 1;
	}
	else {
		cout << "Ficheiro fechado. Incapacitado de escrever para o ficheiro." << endl;
	}
}

void XMLWriter::escreverFimTag() {
	if (out_file.is_open()) {
		indent -= 1;
		for (int i = 0; i < indent; i++) {
			out_file << "\t";
		}
		out_file << "</" << tempOpenTag[openTags - 1] << ">" << endl;
		tempOpenTag.resize(openTags - 1);
		openTags -= 1;
	}
	else {
		cout << "Ficheiro fechado. Incapacitado de escrever para o ficheiro." << endl;
	}
}

XMLWriter::~XMLWriter() {
	if (out_file.is_open()) {
		out_file.close();
		cout << "O Ficheiro xml foi fechado com sucesso." << endl;
	}
	else {
		cout << "O Ficheiro ja esta fechado." << endl;
	}
}
