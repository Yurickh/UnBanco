all:

base_test: BaseTestUnit.o BaseUnit.o
	g++ BaseTestUnit.o BaseUnit.o -o teste

login_test: InterTestUnit.o MainUnit.o UserUnit.o TransacUnit.o PersUnit.o EntityUnit.o BaseUnit.o EngineUnit.o
	g++ InterTestUnit.o MainUnit.o UserUnit.o TransacUnit.o PersUnit.o EntityUnit.o BaseUnit.o EngineUnit.o -o teste

neg_test: NegTestUnit.o MainUnit.o UserUnit.o TransacUnit.o PersUnit.o EntityUnit.o BaseUnit.o EngineUnit.o
	g++ NegTestUnit.o MainUnit.o UserUnit.o TransacUnit.o PersUnit.o EntityUnit.o BaseUnit.o EngineUnit.o -o teste

BaseTestUnit.o: BaseTestUnit.cpp BaseTestUnit.h
	g++ -ansi -Wall -g BaseTestUnit.cpp -c

InterTestUnit.o: InterTestUnit.cpp
	g++ -ansi -Wall -g InterTestUnit.cpp -c

NegTestUnit.o: NegTestUnit.cpp
	g++ -ansi -Wall -g NegTestUnit.cpp -c

MainUnit.o: MainUnit.cpp MainUnit.h
	g++ -ansi -Wall -g MainUnit.cpp -c

TransacUnit.o: TransacUnit.cpp TransacUnit.h
	g++ -ansi -Wall -g TransacUnit.cpp -c

UserUnit.o: UserUnit.cpp UserUnit.h
	g++ -ansi -Wall -g UserUnit.cpp -c

PersUnit.o: PersUnit.cpp PersUnit.h
	g++ -ansi -Wall -g PersUnit.cpp -c

EntityUnit.o: EntityUnit.cpp EntityUnit.h
	g++ -ansi -Wall -g EntityUnit.cpp -c

BaseUnit.o: BaseUnit.cpp BaseUnit.h
	g++ -ansi -Wall -g BaseUnit.cpp -c

EngineUnit.o: EngineUnit.cpp EngineUnit.h
	g++ -ansi -Wall -g EngineUnit.cpp -c

clean: clean_teste clean~ clean.o clean.gch

clean_teste:
	rm teste

clean~:
	rm *~

clean.o:
	rm *.o

clean.gch:
	rm *.gch
