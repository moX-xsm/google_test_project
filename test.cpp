/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年09月15日 星期二 15时03分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<gtest/gtest.h>

int add(int a, int b){
    return a + b;
}

TEST(testFunc, add){
    EXPECT_EQ(add(5, 3), 8);
    ASSERT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 9);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
