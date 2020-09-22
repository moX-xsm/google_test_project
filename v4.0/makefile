all:
	g++ --std=c++11 -I./include -L./lib/ -o ./bin/test ./src/*.cc test.cpp -lgtest -lpthread
run:
	./bin/test
clean:
	rm ./a.out
debug:
	g++ -E --std=c++11 -I./include test.cpp 

