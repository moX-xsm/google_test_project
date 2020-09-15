/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: 2020年09月15日 星期二 15时48分03秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H

//__attribute__((constructor))是函数在main之前执行


#define TEST(a, b) \
void a##__my__##b();\
__attribute__((constructor))\
void add##_my_##a##_my_##b(){\
    add_function(a##__my__##b, #a "__my__" #b);\
}\
void a##__my__##b()

//15行声明  17行将生成的函数放入结构体中 

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "TRUE" : "FALSE")

typedef void (*TestFuncT)();

struct Function{
    TestFuncT func;
    const char *str;
};

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
#endif
