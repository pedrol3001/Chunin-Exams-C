main : lista.o arvore.o

	gcc -o main main.c lista.o arvore.o -lm

lista.o:

	gcc -c lista.c

arvore.o:

	gcc -c arvore.c

clean:	

	rm *.o