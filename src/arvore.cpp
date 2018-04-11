#include <arvore.h>
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

No* Arvore::criaNo(std::string dado){
	No *no = new (nothrow) No;
	no->esquerda = NULL;
	no->direita = NULL;
	no->dado = dado;
	tamanho_++;

return no;
}

void Arvore::adicionaNo(No* novoNo){
	if(Vazia()){
		raiz_ = novoNo;
	}else if(raiz_->esquerda == NULL){
		raiz_->esquerda = novoNo;
	}else{
		raiz_->direita = novoNo;
	}
}

void Arvore::adicionaNo(std::string dado){
	No *novoNo = criaNo(dado);
	adicionaNo(novoNo);
}
	
