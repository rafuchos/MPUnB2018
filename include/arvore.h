#ifndef ARVORE_H
#define ARVORE_H

#include <string>
#include <queue>
#include <list>
#include <iostream>

struct No {
	int dado;
	No *esquerda;
	No *direita;
	std::string valor;
};


class Arvore {
	No *raiz_;
	int tamanho_;
	No* pesquisaNo(int dado, No *folha);
	void adicionaNo(int dado, No *novoNo, std::string valor);
	void deletaNo(No *no);

	public:
	  Arvore();
	  ~Arvore();
	  bool Vazia() const;
	  unsigned long tamanho() const;
	  void adicionaNo(int dado, std::string valor);
	  No *pesquisaNo(int dado);
	  No *pegaRaiz();
	  void deletaNo();


};

#endif

