#include <arvore.h>
#include"gtest/gtest.h"
#include <iostream>
#include <sstream>
using namespace std;

int main (void){
	///Cria a árvore com as perguntas do jogo
	Arvore jogo;
	No *noatual;
	std::string resposta;
	jogo.adicionaNo(50,"É de comer?");
	jogo.adicionaNo(30,"Sim");
	jogo.adicionaNo(7,"É doce?");
	jogo.adicionaNo(6,"Sim");
	jogo.adicionaNo(3,"É brasileiro?");
	jogo.adicionaNo(2,"Sim");
	jogo.adicionaNo(1,"É doce de leite!");
	jogo.adicionaNo(4,"Não");
	jogo.adicionaNo(5,"É chocolate!");
	jogo.adicionaNo(17,"Não");
	jogo.adicionaNo(25,"É salgado?");
	jogo.adicionaNo(23,"Sim");
	jogo.adicionaNo(20,"É brasileiro?");
	jogo.adicionaNo(19,"Sim");
	jogo.adicionaNo(18,"É coxinha!");
	jogo.adicionaNo(21,"Não");
	jogo.adicionaNo(22,"");
	jogo.adicionaNo(60,"Não");
	jogo.adicionaNo(70,"É um objeto?");
	jogo.adicionaNo(65,"Sim");
	jogo.adicionaNo(63,"É um computador!");
	jogo.adicionaNo(75,"Não");
	jogo.adicionaNo(80,"É uma pessoa?");
	jogo.adicionaNo(77,"Sim");
	jogo.adicionaNo(76,"É a Angelina Jolie!");
	jogo.adicionaNo(81,"Não");
	jogo.adicionaNo(82,"Não sei o que é!");
	///Começa a interação com o Usuário
	cout << "Olá, o jogo vai começar, responda as perguntas com Sim e Não" << endl;
	noatual = jogo.pegaRaiz();
	cout << noatual->valor << endl;
	cin >> resposta;
	if(resposta == "Sim"){
		if(noatual->esquerda == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->esquerda->esquerda;
		}
	}
	else{	
		if(noatual->direita == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->direita->direita;
		}
	}
	cout << noatual->valor << endl;
	cin >> resposta;
	if(resposta == "Sim"){
		if(noatual->esquerda == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->esquerda->esquerda;
		}
	}
	else{	
		if(noatual->direita == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->direita->direita;
		}
	}
	cout << noatual->valor << endl;
	cin >> resposta;
	if(resposta == "Sim"){
		if(noatual->esquerda == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->esquerda->esquerda;
		}
	}
	else{	
		if(noatual->direita == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->direita->direita;
		}
	}
	cout << noatual->valor << endl;
	cin >> resposta;
	if(resposta == "Sim"){
		if(noatual->esquerda == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->esquerda->esquerda;
		}
	}
	else{	
		if(noatual->direita == NULL){
			cout << "Fim!" << endl;
		}
		else{
			noatual = noatual->direita->direita;
		}
	}

return 0;
}


