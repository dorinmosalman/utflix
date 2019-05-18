CC = g++ --std=c++11

all: a.out clean

a.out: main.o Profile.o User.o Film.o Publisher.o Manager.o Interface.o Command.o Login.o Signup.o Films.o Followers.o Money.o Buy.o Accounting.o Rate.o Notification.o Notifications.o Comment.o
	$(CC) main.o Profile.o User.o Film.o Publisher.o Manager.o Interface.o Command.o Login.o Signup.o Films.o Followers.o Money.o Buy.o Accounting.o Rate.o Notification.o Notifications.o Comment.o -o a.out

main.o: main.cpp Interface.h
	$(CC) -c main.cpp -o main.o

Interface.o: Interface.cpp Interface.h Exceptions.h Manager.h Command.h
	$(CC) -c Interface.cpp -o Interface.o

Command.o: Command.cpp Command.h Exceptions.h Manager.h Film.h Signup.h Login.h Films.h Followers.h Money.h Buy.h Rate.h Notifications.o
	$(CC) -c Command.cpp -o Command.o

Profile.o: Profile.cpp Profile.h Exceptions.h Notification.h
	$(CC) -c Profile.cpp -o Profile.o

User.o: User.cpp User.h Profile.h Film.h
	$(CC) -c User.cpp -o User.o

Publisher.o: Publisher.cpp Publisher.h Profile.h Film.h Manager.h
	$(CC) -c Publisher.cpp -o Publisher.o

Manager.o: Manager.cpp Manager.h Profile.h Exceptions.h Accounting.h
	$(CC) -c Manager.cpp -o Manager.o

Film.o: Film.cpp Film.h Comment.h
	$(CC) -c Film.cpp -o Film.o

Login.o: Login.cpp Login.h Manager.h
	$(CC) -c Login.cpp -o Login.o

Signup.o: Signup.cpp Signup.h Manager.h
	$(CC) -c Signup.cpp -o Signup.o

Films.o: Films.cpp Films.h Manager.h Profile.h
	$(CC) -c Films.cpp -o Films.o

Followers.o: Followers.cpp Followers.h Manager.h Exceptions.h
	$(CC) -c Followers.cpp -o Followers.o

Money.o: Money.cpp Money.h Manager.h Exceptions.h
	$(CC) -c Money.cpp -o Money.o

Buy.o: Buy.cpp Buy.h Manager.h Exceptions.h Film.h
	$(CC) -c Buy.cpp -o Buy.o

Accounting.o: Accounting.cpp Accounting.h Film.h
	$(CC) -c Accounting.cpp -o Accounting.o

Rate.o: Rate.cpp Rate.h Manager.h
	$(CC) -c Rate.cpp -o Rate.o

Notification.o: Notification.cpp Notification.h
	$(CC) -c Notification.cpp -o Notification.o

Notifications.o: Notifications.cpp Notifications.h Manager.h
	$(CC) -c Notifications.cpp -o Notifications.o

Comment.o: Comment.cpp Comment.h
	$(CC) -c Comment.cpp -o Comment.o

.PHONY: clean
clean:
	find . -type f | xargs touch
	rm *.o