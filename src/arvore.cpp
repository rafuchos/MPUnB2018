#include <arvore.h>
#include <iostream>
#include <new>
#include <sstream>
#include <queue>
#include <stack>
#include <list>

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
	if(no !=NULL){
		deletaNo(no->esquerda);
		deletaNo(no->direita);
		if (no == raiz_){
			raiz_ = NULL;
			tamanho_= 0;
		}	
		else {
			no = NULL;
			tamanho_--;
		}
		delete no;
		
	}
}

Arvore::~Arvore() {
	deletaNo(raiz_);
}

/*void Arvore::deletaNo(){
	deletaNo(raiz_);
}*/
void Arvore::adicionaNo(int dado, No* novoNo, std::string valor){
	if(dado < novoNo->dado){
		if(novoNo->esquerda != NULL){
			adicionaNo(dado, novoNo->esquerda, valor);
		}
		else{
			novoNo->esquerda = new (nothrow) No;
			novoNo->esquerda->esquerda = NULL;
			novoNo->esquerda->direita = NULL;
			novoNo->esquerda->dado = dado;
			novoNo->esquerda->valor = valor;
			tamanho_++;
		}
	}
	else if(dado >= novoNo->dado){
		if(novoNo->direita != NULL){
			adicionaNo(dado, novoNo->direita, valor);
		}
		else{
			novoNo->direita = new (nothrow) No;
			novoNo->direita->esquerda = NULL;
			novoNo->direita->direita = NULL;
			novoNo->direita->dado = dado;
			novoNo->direita->valor = valor;
			tamanho_++;
		}	
	}
}

void Arvore::adicionaNo(int dado, std::string valor){
	if(raiz_ != NULL){
		adicionaNo(dado, raiz_, valor);
	}
	else{
		raiz_ = new (nothrow) No;
		raiz_->dado = dado;
		raiz_->esquerda = NULL;
		raiz_->direita = NULL;
		raiz_->valor = valor;
		tamanho_++;
	}
}

No *Arvore::pesquisaNo(int dado, No *folha){
	if(folha != NULL){
		if(dado == folha->dado){
			return folha;
		}
		if(dado < folha->dado){
			return pesquisaNo(dado, folha->esquerda);
		}
		else{
			return pesquisaNo(dado, folha->direita);
		}
	}
	else{
		return NULL;
	}
}
No *Arvore::pesquisaNo(int dado){
	return pesquisaNo(dado, raiz_);
}

No *Arvore::pegaRaiz(){
	return raiz_;
}


	
