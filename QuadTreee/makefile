CC= g++ 
CFLAGS= -ggdb -Wno-deprecated -Wall 

objetos=  QuadTree.cpp 

QT: $(objetos)
	$(CC)-o $@ $^
QuadTree: QuadTree_.cpp
	 $(CC) $(CFLAGS) -c -o $@ $^


clean:
	rm -rf QT *.o
