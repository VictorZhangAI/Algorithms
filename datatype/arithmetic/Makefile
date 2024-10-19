arithmetic: arithmetic.o Stack.o
	g++ arithmetic.o Stack.o -o arithmetic

arithmetic.o: arithmetic.cpp Stack.h
	g++ -c arithmetic.cpp Stack.h

.PHONY: clean
clean:
	rm -rf *.o arithmetic

.PHONY: final

final:
	rm -rf *.o arithmetic *.gch
