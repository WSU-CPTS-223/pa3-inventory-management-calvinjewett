out: clean compile execute

compile: main.cpp
	g++ -g -Wall -std=c++14 main.cpp product.cpp functions.cpp -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe