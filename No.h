#pragma once
class No
{
	friend class ArvBinBusca;

public:
	No(const int chave);

	void escreve(const char* sep = "");

private:
	int chave;
	No* pai;
	No* esq;
	No* dir;

};

