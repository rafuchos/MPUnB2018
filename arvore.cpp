#include "arvore.h"
#include<iostream>
#include<new>
#include<sstream>
#include<queue>
#include<stack>
#include<list>

using namespace std;

Arvore::Arvore(){
	raiz_ = NULL;
	tamanho_ = 0;
}

bool Arvore::Vazia() const {
	return (raiz_ == NULL);
}

unsigned long Arvore::tamanho() const {
	return tamanho_;
}

void Arvore::deletaNo(No *no){
	if(no ==NULL) return;
	deletaNo(no->esquerda);
	deletaNo(no->direita);
	delete no;
}

Arvore::~Arvore() {
	deletaNo(raiz_);
}
