CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11

OBJS = MyBitManipulation.o Myfloat.o MyIntegers.o test_hw3.o

all: hw3

hw3: $(OBJS)
	$(CC) $(CFLAGS) -o hw3 $(OBJS)

MyBitManipulation.o: MyBitManipulation.c MyBitManipulation.h
	$(CC) $(CFLAGS) -c MyBitManipulation.c

Myfloat.o: Myfloat.c Myfloat.h
	$(CC) $(CFLAGS) -c Myfloat.c

MyIntegers.o: MyIntegers.c MyIntegers.h
	$(CC) $(CFLAGS) -c MyIntegers.c

test_hw3.o: test_hw3.c MyBitManipulation.h Myfloat.h MyIntegers.h
	$(CC) $(CFLAGS) -c test_hw3.c

clean:
	rm -f *.o hw3
