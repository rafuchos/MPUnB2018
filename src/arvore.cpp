#include <arvore.h>
#include <iostream>
#include <new>
#include <sstream>
#include <queue>
#include <stack>
#include <list>

using namespace std;

///Inicializa as variáveis da Arvore
Arvore::Arvore(){
	raiz_ = NULL;
	tamanho_ = 0;
}

///Retorna Verdadeiro ou Falso se a raiz for nula
bool Arvore::Vazia() const {
	return (raiz_ == NULL);
}

///Retorna o tamanho da arvore
unsigned long Arvore::tamanho() const {
	return tamanho_;
}

///Deleta um nó especifico da arvore e atualiza o tamanho
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

///Deleta a raiz da arvore
Arvore::~Arvore() {
	deletaNo(raiz_);
}

///Adiciona um nó em uma posição dado especifica com um valor específico
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

///Adiciona uma raiz se ainda não houver, caso contrário chama a função
///adciona nó com o nó a ser adicionado
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

///Pesquisa a árvore pelo dado e retorna o nó correspondente ao dado
///se não houver retorna NULL
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

///Pesquisa o dado na árvore toda a partir da raiz
No *Arvore::pesquisaNo(int dado){
	return pesquisaNo(dado, raiz_);
}

///Retorna o nó raiz
No *Arvore::pegaRaiz(){
	return raiz_;
}


	
