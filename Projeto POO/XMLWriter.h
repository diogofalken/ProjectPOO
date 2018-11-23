#pragma once
class XMLWriter {
private:
	ofstream out_file;
	int indent;
	int openTags;
	int openElements;
	vector<string> tempOpenTag;
	vector<string> tempElementTag;
public:
	XMLWriter();
	bool escreverPrincipioPrograma(string file_name);
	void escreverElementoString(string element, string value);
	void escreverPrincipioElemento(string element);
	void escreverFimElemento();
	void escreverPrincipioTag(string tag);
	void escreverFimTag();
	~XMLWriter();
};

