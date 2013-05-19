all:

teste: TestUnit.o BaseUnit.o
	g++ TestUnit.o BaseUnit.o -o teste

TestUnit.o: TestUnit.cpp TestUnit.h
	g++ TestUnit.cpp -c

EntityUnit.o: EntityUnit.cpp EntityUnit.h BaseUnit.h
	g++ EntityUnit.cpp -c

BaseUnit.o: BaseUnit.cpp BaseUnit.h
	g++ BaseUnit.cpp -c

clean: clean~ clean.o clean.gch

clean~:
	rm *~

clean.o:
	rm *.o

clean.gch:
	rm *.gch
