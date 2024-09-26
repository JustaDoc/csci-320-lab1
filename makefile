explode: lab1.o main.o
	$(CC) -o $@ $?

lab1.o: lab1.c lab1.h
	$(CC) -c $?

main.o: main.c lab1.h
	$(CC) -c $?

clean:
	-rm -f *.o explode
