all:
	g++ --std=c++11 -I./include -L./lib/ test.cpp -lgtest -lpthread
clean:
	rm ./a.out
