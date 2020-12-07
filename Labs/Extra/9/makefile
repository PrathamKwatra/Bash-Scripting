
cc := gcc
FLAGS :=

arr : main-arr.o stack-arr.o
	$(cc) $(FLAGS) $^  -o $@

main-arr.o : main-arr.c stack-arr.h
	$(cc) $(FLAGS) -c $<

stack-arr.o : stack-arr.c stack-arr.h
	$(cc) $(FLAGS) -c $<

ll : main-ll.o stack-ll.o
	$(cc) $(FLAGS) $^  -o $@

main-ll.o : main-ll.c stack-ll.h
	$(cc) $(FLAGS) -c $<

stack-ll.o : stack-ll.c stack-ll.h
	$(cc) $(FLAGS) -c $<

.PHONY : clean cleanall

clean :
	-\rm *.o

cleanall :
	-\rm ll
	-\rm arr
	-\rm *.o
