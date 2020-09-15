/*************************************************************************
	> File Name: test.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年09月15日 星期二 15时03分55秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<mytest/test.h>

int add(int a, int b){
    return a + b;
}
//TEST没有返回值 没有类型 这是一个宏
TEST(testFunc, add){
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 9);
}

TEST(testFunc, add2){
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 9);
}
TEST(test, Funcadd){
    EXPECT_EQ(add(5, 3), 8);
    EXPECT_EQ(add(5, 3), 9);
    EXPECT_EQ(add(6, 7), 9);
}

int main(int argc, char **argv){
    return RUN_ALL_TESTS();
}
