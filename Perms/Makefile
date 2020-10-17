exp: exp.o decreasedDecimal.o increasedDecimal.o lexiOrder.o orthoTransposition.o randomOrder.o shuffledOrder.o utils.o 
	g++ exp.o decreasedDecimal.o increasedDecimal.o lexiOrder.o orthoTransposition.o randomOrder.o shuffledOrder.o utils.o -o exp
main: main.o decreasedDecimal.o increasedDecimal.o lexiOrder.o orthoTransposition.o shuffledOrder.o utils.o
	g++ main.o decreasedDecimal.o increasedDecimal.o lexiOrder.o orthoTransposition.o shuffledOrder.o utils.o -o main
decreasedDecimal.o: decreasedDecimal.cpp
	g++ -c decreasedDecimal.cpp -O2 -std=c++11
increasedDecimal.o: increasedDecimal.cpp
	g++ -c increasedDecimal.cpp -O2 -std=c++11
lexiOrder.o: lexiOrder.cpp
	g++ -c lexiOrder.cpp -O2 -std=c++11
orthoTransposition.o: orthoTransposition.cpp
	g++ -c orthoTransposition.cpp -O2 -std=c++11
utils.o: utils.cpp
	g++ -c utils.cpp -O2 -std=c++11
main.o: main.cpp
	g++ -c main.cpp -O2 -std=c++11
randomOrder.o: randomOrder.cpp
	g++ -c randomOrder.cpp -O2 -std=c++11
shuffledOrder.o: shuffledOrder.cpp
	g++ -c shuffledOrder.cpp -O2 -std=c++11
exp.o: exp.cpp
	g++ -c exp.cpp -O2 -std=c++11
clean:
	rm -f *.o
	rm -f main
	rm -f exp