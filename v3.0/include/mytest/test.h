/*************************************************************************
	> File Name: test.h
	> Author: 
	> Mail: 
	> Created Time: 2020年09月15日 星期二 15时48分03秒
 ************************************************************************/

#ifndef _TEST_H
#define _TEST_H
#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
#define BLUE(a) COLOR(a, 34)
#define YELLOW(a) COLOR(a, 33)

#define COLOR_HL(a, b) "\033[1;" #b "m" a "\033[0m"
#define GREEN_HL(a) COLOR_HL(a, 32)
#define RED_HL(a) COLOR_HL(a, 31)
#define BLUE_HL(a) COLOR_HL(a, 34)
#define YELLOW_HL(a) COLOR_HL(a, 33)
//__attribute__((constructor))是函数在main之前执行

#define TEST(a, b) \
void a##__my__##b();\
__attribute__((constructor))\
void add##_my_##a##_my_##b(){\
    add_function(a##__my__##b, #a "." #b);\
}\
void a##__my__##b()

//15行声明  17行将生成的函数放入结构体中 


#define TYPE_STR(a) _Generic((a), \
    int : "%d", \
    double : "%lf", \
    float : "%f", \
    long long : "%lld", \
    const char * : "%s" \
)
#define P(a, color) { \
    char frm[1000]; \
    sprintf(frm, color("%s"), TYPE_STR(a)); \
    printf(frm, a); \
}


#define EXPECT(a, b, cmp) { \
    __typeof(a) _a = (a);\
    __typeof(b) _b = (b);\
    printf(GREEN("[-----------] ") #a " " #cmp " " #b);\
    printf(" %s\n", (_a) cmp (_b) ? GREEN_HL("TRUE") : RED_HL("FALSE"));\
    info.total += 1;\
    if(_a cmp _b) info.success += 1;\
    else{\
        printf("\n");\
        printf(YELLOW_HL("\t%s:%d: Failure\n"), __FILE__, __LINE__);\
        printf(YELLOW_HL("\t\texpect" #a " " #cmp " " #b ));\
        printf("\n\n");\
    }\
}


#define EXPECT_EQ(a, b) EXPECT(a, b, ==)
#define EXPECT_LT(a, b) EXPECT(a, b, <)
#define EXPECT_GT(a, b) EXPECT(a, b, >)
#define EXPECT_LE(a, b) EXPECT(a, b, <=)
#define EXPECT_GE(a, b) EXPECT(a, b, >=)
#define EXPECT_NE(a, b) EXPECT(a, b, !=)


typedef void (*TestFuncT)();

struct Function{
    TestFuncT func;
    const char *str;
};
struct FunctionInfo{
    int total, success;
};
int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);
#endif
