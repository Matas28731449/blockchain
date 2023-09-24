main: clean
	g++ -std=c++11 -O3 -w -o main main.cpp
clean:
	rm -f *.o main