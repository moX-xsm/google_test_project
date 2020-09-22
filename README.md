gtest单元测试框架

- 单元测试：c语言中单元测试指函数测试 java为类的测试

- gtest

- makefile对于不同的主机环境是不同的，而cmake会根据本机当前的环境生成makefile

  `cmake CMakeList.txt`  之后在make即可

若干个对象文件.o文件打包后就是一个静/动态链接库  放的是函数的定义

函数的声明会放在一组头文件中

任何一个第三方库给我们提供相应的功能时，最好的方法就是给我们一个链接库+一组头文件

静态链接库一般放在lib中 头文件一般放在include中

- 添加静态链接库 -L  `g++ -L ./lib test.cpp -lgtest` 在lib中寻找libgtest.a静态库
- 添加头文件搜索路径 `g++ -I ./include test.cpp` cpp文件中的头文件用<>

最终编译命令`g++ -L ./lib -I ./include test.cpp -lgtest -lpthread`

test.cpp

```cpp
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

```

makefile内容：

```cpp
all:
	g++ --std=c++11 -I./include -L./lib/ test.cpp -lgtest -lpthread
clean:
	rm ./a.out

```

设计链表结构存储未知个数个函数信息  减少存储空间

![image-20200922154843671](https://gitee.com/xsm970228/images/raw/master/20200922154854.png)

