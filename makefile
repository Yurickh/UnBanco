all:

BaseUnit: BaseUnit.cpp BaseUnit.h
	g++ BaseUnit.cpp BaseUnit.h -c

EntityUnit: EntityUnit.cpp EntityUnit.h
	g++ EntityUnit.cpp EntityUnit.h -c

clean:
	rm *.o
