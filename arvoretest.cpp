#include "arvore.h"	
#include"gtest/gtest.h" ///Google test library
#include<list>
#include<string>

TEST(TestaArvore, ArvoreVazia){
	Arvore a;
	EXPECT_TRUE(a.isEmpty());
	EXPECT_EQ(0,a.size());
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
