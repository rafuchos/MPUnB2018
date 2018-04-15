#ifndef ARVORE_H
#define ARVORE_H

#include<string>
#include<queue>
#include<list>

struct No {
	std::string dado;
	No *esquerda;
	No *direita;
};


class Arvore {
	No *raiz_;
	int tamanho_;
	No* pesquisaNo(std::string dado, No *folha) const;
	void adicionaNo(std::string dado, No *novoNo);

	public:
	  void deletaNo(No *no);
	  Arvore();
	  ~Arvore();
	  bool Vazia() const;
	  unsigned long tamanho() const;
	  void adicionaNo(std::string dado);
	  No *pesquisaNo(std::string dado);


};

#endif

