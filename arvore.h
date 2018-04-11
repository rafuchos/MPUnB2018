#ifndef ARVORE_H
#define ARVORE_H

#include<string>
#include<queue>
#include<list>

struct No {
	char dado[30];
	No *esquerda;
	No *direita;
};


class Arvore {
	No *raiz_;
	int tamanho_;
	No* criaNo(No *no);
	void deletaNo(No *no);
	void ordem(No *arvore, std::string &str) const;

	public:
	  Arvore();
	  ~Arvore();
	  bool Vazia() const;
	  unsigned long tamanho() const;
	  void add(char dado[30]);
	  void add(No *novoNo);
	  No* pegaRaiz() const;
};

#endif

