#include <arvore.h>	
#include"gtest/gtest.h" ///Google test library
#include <list>
#include <string>
#include <iostream>
using namespace std;
TEST(TestaArvore, ArvoreVazia){
	Arvore a;
	EXPECT_TRUE(a.Vazia());
	EXPECT_EQ(0,a.tamanho());
}

TEST(TestaArvore, AdicionaNo){
	Arvore umNo, variosNos;
	umNo.adicionaNo(3,"É de beber?");
	EXPECT_FALSE(umNo.Vazia());
	EXPECT_EQ(1, umNo.tamanho());
	variosNos.adicionaNo(5,"É de comer?");
	variosNos.adicionaNo(4,"Sim");
	variosNos.adicionaNo(6,"Não");
	variosNos.adicionaNo(3,"teste");
	EXPECT_FALSE(variosNos.Vazia());
	EXPECT_EQ(4, variosNos.tamanho());
}	

TEST(TestaArvore, DeletaNo){
	Arvore umNo, variosNos;
	umNo.adicionaNo(3,"É de beber?");
	umNo.deletaNo(umNo.pesquisaNo(3));
	EXPECT_TRUE(umNo.Vazia());
	variosNos.adicionaNo(5,"É de comer?");
	variosNos.adicionaNo(4,"Sim");
	variosNos.adicionaNo(6,"Não");
	variosNos.adicionaNo(3,"teste");
	EXPECT_EQ(4, variosNos.tamanho());
	variosNos.deletaNo(variosNos.pesquisaNo(3));
	EXPECT_EQ(3, variosNos.tamanho());
}

TEST(TestaArvore, PesquisaNo){
	Arvore pesquisa;
	No *no;
	No *nodelete;
	pesquisa.adicionaNo(1,"Olá");
	no = pesquisa.pesquisaNo(1);
	cout << no->valor << endl;
	EXPECT_EQ(pesquisa.pegaRaiz(),no);
	pesquisa.adicionaNo(2,"Olá 2");
	pesquisa.deletaNo(pesquisa.pesquisaNo(1));
	nodelete = pesquisa.pesquisaNo(1);
	EXPECT_EQ(NULL,nodelete);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
