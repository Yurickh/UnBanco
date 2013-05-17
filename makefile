all:

EntityUnit.o: EntityUnit.cpp EntityUnit.h BaseUnit.h
	g++ EntityUnit.cpp -c

BaseUnit.o: BaseUnit.cpp BaseUnit.h
	g++ BaseUnit.cpp -c

clean:
	rm *.o
