CC = g++
CFlags = -g -w -Wall

main: most_active_cookie.o Dataframe.o
	$(CC) $(CFLAGS) -o most_active_cookie most_active_cookie.o Dataframe.o

test_unit: test_unit.o Dataframe.o
	$(CC) $(CFLAGS) -o test_unit test_unit.o Dataframe.o

Dataframe.o: Dataframe.hpp Dataframe.cpp
	$(CC) $(CFLAGS) -c Dataframe.cpp

clean:
	rm -f core *.o main test_unit