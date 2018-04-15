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
	tamanho_--;
	delete no;
}

Arvore::~Arvore() {
	deletaNo(raiz_);
}

void Arvore::adicionaNo(std::string dado, No* novoNo){
	if(novoNo->esquerda != NULL){
		adicionaNo(dado, novoNo->esquerda);
	}
	else if(novoNo->direita != NULL){
		adicionaNo(dado, novoNo->direita);
	}
	else{
		novoNo->esquerda = new (nothrow) No;
		novoNo->esquerda->esquerda = NULL;
		novoNo->esquerda->direita = NULL;
		novoNo->esquerda->dado = dado;
		tamanho_++;
	}

}

void Arvore::adicionaNo(std::string dado){
	if(raiz_ != NULL){
		adicionaNo(dado, raiz_);
	}
	else{
		raiz_ = new (nothrow) No;
		raiz_->dado = dado;
		raiz_->esquerda = NULL;
		raiz_->direita = NULL;
		tamanho_++;
	}
}


	
