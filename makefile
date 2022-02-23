all: main.o Student.o Room.o Date.o Reservation.o Library.o
	g++ -o a1 main.o Student.o Room.o Date.o Reservation.o Library.o

make a1: main.o Student.o Room.o Date.o Reservation.o Library.o
	g++ -o a1 main.o Student.o Room.o Date.o Reservation.o Library.o

main.o: main.cc Student.h
	g++ -c main.cc

Student.o: Student.cc Student.h
	g++ -c Student.cc

Room.o: Room.cc Room.h
	g++ -c Room.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

Reservation.o: Reservation.cc Reservation.h
	g++ -c Reservation.cc

Library.o: Library.cc Library.h
	g++ -c Library.cc

clean:
	rm -f *.o a1