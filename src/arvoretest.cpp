#include <arvore.h>	
#include"gtest/gtest.h" ///Google test library
#include<list>
#include<string>

TEST(TestaArvore, ArvoreVazia){
	Arvore a;
	EXPECT_TRUE(a.Vazia());
	EXPECT_EQ(0,a.tamanho());
}

TEST(TestaArvore, AdicionaNo){
	Arvore umNo, variosNos;
	umNo.adicionaNo("É de beber?");
	EXPECT_FALSE(umNo.Vazia());
	EXPECT_EQ(1, umNo.tamanho());
	variosNos.adicionaNo("É de comer?");
	variosNos.adicionaNo("Sim");
	variosNos.adicionaNo("Não");
	variosNos.adicionaNo("teste");
	EXPECT_FALSE(variosNos.Vazia());
	EXPECT_EQ(4, variosNos.tamanho());
}	

TEST(TestaArvore, DeletaNo){
	Arvore umNo, variosNos;
	umNo.adicionaNo("É de beber?");
	umNo.deletaNo(pesquisaNo("É de beber?"));
	EXPECT_TRUE(umNo.Vazia());
	variosNos.adicionaNo("É de comer?");
	variosNos.adicionaNo("Sim");
	variosNos.adicionaNo("Não");
	variosNos.adicionaNo("teste");
	EXPECT_EQ(4, variosNos.tamanho());
	variosNos.deletaNo(pesquisaNo("teste"));
	EXPECT_EQ(3, variosNos.tamanho());
}

TEST(TestaArvore, PesquisaNo){
	Arvore pesquisa;
	No *no;
	No *nodelete;
	pesquisa.adicionaNo("Olá");
	no = pesquisa.pesquisaNo("Olá");
	EXPECT_EQ(pesquisa->raiz_,no);
	pesquisa.deletaNo(no);
	nodelete = pesquisa.pesquisaNo("Olá");
	EXPECT_EQ(NULL,nodelete);
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
