CC = g++ --std=c++11

all: a.out

a.out: main.o Profile.o User.o Publisher.o Manager.o Interface.o Command.o
	$(CC) main.o Profile.o User.o Publisher.o Manager.o Interface.o Command.o -o a.out

main.o: main.cpp main.o Profile.h Manager.h Interface.h Command.h
	$(CC) -c main.cpp -o main.o

Interface.o: Interface.cpp Interface.h Exceptions.h Manager.h Command.h
	$(CC) -c Interface.cpp -o Interface.o

Command.o: Command.cpp Command.h Exceptions.h Manager.h
	$(CC) -c Command.cpp -o Command.o

Profile.o: Profile.cpp Profile.h Exceptions.h
	$(CC) -c Profile.cpp -o Profile.o

User.o: User.cpp User.h Profile.h
	$(CC) -c User.cpp -o User.o

Publisher.o: Publisher.cpp Publisher.h Profile.h Film.h
	$(CC) -c Publisher.cpp -o Publisher.o

Manager.o: Manager.cpp Manager.h Profile.h Exceptions.h
	$(CC) -c Manager.cpp -o Manager.o

Film.o: Film.cpp
	$(CC) -c Film.cpp -o Film.o

.PHONY: clean
clean:
	rm *.o
	rm a.out