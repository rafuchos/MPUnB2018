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
	No* criaNo(std::string dado);
	void deletaNo(No *no);

	public:
	  Arvore();
	  ~Arvore();
	  bool Vazia() const;
	  unsigned long tamanho() const;
	  void adicionaNo(std::string dado);
	  void adicionaNo(No *novoNo);
	  No* pegaRaiz() const;
};

#endif

