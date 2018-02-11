multiply: main.o product.o print.o
	g++ -o multiply main.o product.o print.o

main.o: main.cpp functions.h
	g++ -c main.cpp

product.o: product.cpp functions.h
	g++ -c product.cpp

print.o: print.cpp functions.h
	g++ -c print.cpp

clean:
	rm -f *.o multiply