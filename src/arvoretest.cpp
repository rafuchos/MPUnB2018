#include <arvore.h>	
#include"gtest/gtest.h" ///Google test library
#include <list>
#include <string>
#include <iostream>
using namespace std;
///Testa se a árvore está de fato vazia
TEST(TestaArvore, ArvoreVazia){
	Arvore a;
	EXPECT_TRUE(a.Vazia());
	///Também verifica se o tamanho é de fato 0
	EXPECT_EQ(0,a.tamanho());
}

///Teste para a função de adiciona nó
TEST(TestaArvore, AdicionaNo){
	///Primeira parte: adiciona um nó, depois vê se
	///a árvore não está vazia e se o tamanho é 1
	Arvore umNo, variosNos;
	umNo.adicionaNo(3,"É de beber?");
	EXPECT_FALSE(umNo.Vazia());
	EXPECT_EQ(1, umNo.tamanho());
	///Segunda parte: adiciona quatro nós, depois vê se
	///a árvore não está vazia e o tamanho é 4
	variosNos.adicionaNo(5,"É de comer?");
	variosNos.adicionaNo(4,"Sim");
	variosNos.adicionaNo(6,"Não");
	variosNos.adicionaNo(3,"teste");
	EXPECT_FALSE(variosNos.Vazia());
	EXPECT_EQ(4, variosNos.tamanho());
}	

///Teste para as funções que deletam nó
TEST(TestaArvore, DeletaNo){
	///Primeira parte: adiciona um nó, depois deleta e ve se
	///a árvore está de fato vazia
	Arvore umNo, variosNos;
	umNo.adicionaNo(3,"É de beber?");
	umNo.deletaNo(umNo.pesquisaNo(3));
	EXPECT_TRUE(umNo.Vazia());
	///Segunda parte: adiciona quatro nós, depois deleta 1
	///e vê se o tamanho muda de 3 para 4
	variosNos.adicionaNo(5,"É de comer?");
	variosNos.adicionaNo(4,"Sim");
	variosNos.adicionaNo(6,"Não");
	variosNos.adicionaNo(3,"teste");
	EXPECT_EQ(4, variosNos.tamanho());
	variosNos.deletaNo(variosNos.pesquisaNo(3));
	EXPECT_EQ(3, variosNos.tamanho());
}

///Teste para a função de pesquisa de um nó e a função pegaRaiz
TEST(TestaArvore, PesquisaNo){
	///Primeira parte: adiciona um nó, no caso a raiz e depois vê
	///pesquisando se o nó adicionado é igual ao nó raiz
	Arvore pesquisa;
	No *no;
	No *nodelete;
	pesquisa.adicionaNo(1,"Olá");
	no = pesquisa.pesquisaNo(1);
	EXPECT_EQ(pesquisa.pegaRaiz(),no);
	///Segunda parte: adiciona um nó, deleta o nó utilizando a 
	///função de pesquisa e checa se o nó de fato foi deletado
	///verificando que quando a pesquisa não encontra retorna NULL
	pesquisa.adicionaNo(2,"Olá 2");
	pesquisa.deletaNo(pesquisa.pesquisaNo(1));
	nodelete = pesquisa.pesquisaNo(1);
	EXPECT_EQ(NULL,nodelete);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
