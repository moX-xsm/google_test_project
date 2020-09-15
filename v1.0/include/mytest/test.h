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
__attribute__((constructor))\
void a##__my__##b()

#define EXPECT_EQ(a, b) printf("%s == %s ? %s\n", #a, #b, (a) == (b) ? "TRUE" : "FALSE")


int RUN_ALL_TESTS();

#endif
