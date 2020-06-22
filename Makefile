all: main

main: main.o ExtensibleHashTable.o Bucket.o Bucket.h
	g++ -o main main.o ExtensibleHashTable.o Bucket.o

main.o: main.cpp ExtensibleHashTable.o ExtensibleHashTable.h 
	g++ -c main.cpp

ExtensibleHashTable.o: ExtensibleHashTable.cpp ExtensibleHashTable.h Bucket.o Bucket.h
	g++ -c ExtensibleHashTable.cpp

Bucket.o: Bucket.cpp Bucket.h
	g++ -c Bucket.cpp

clean:
	rm -f main *.o