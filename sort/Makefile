Lib:
	g++ -O3 -c -fPIC -Wall -Wextra -Wpedantic -Werror sort.cpp -o sort.o
	g++ -O3 -shared sort.o -o libsort.so
	rm sort.o

install:
	cp sort.hpp /usr/local/include/
	cp libsort.so /usr/local/lib/
