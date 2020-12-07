shell = /bin/sh

cc = gcc
flags =

265inventory : main.o
	$(cc) $(flags) main.c -o $@

main.o : main.c
	$(cc) -c $(flags) main.c

.PHONY : view run clean

view :
	cat main.c | less

run : 265inventory
	./265inventory

clean :
	rm *.o 265inventory
