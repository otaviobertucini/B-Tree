all: saida
	@echo " "
	@echo "Copilação concluída!!"
	@echo " "

saida: mainArvoreb.o buscaArvoreb.o insereArvoreb.o criaArvoreb.o printArvoreb.o removeArvoreb.o
	gcc -o saida mainArvoreb.o buscaArvoreb.o insereArvoreb.o criaArvoreb.o printArvoreb.o removeArvoreb.o

mainArvoreb.o: mainArvoreb.c
	gcc -o mainArvoreb.o -c mainArvoreb.c

buscaArvoreb.o: buscaArvoreb.c
	gcc -o buscaArvoreb.o -c buscaArvoreb.c

insereArvoreb.o: insereArvoreb.c
	gcc -o insereArvoreb.o -c insereArvoreb.c

criaArvoreb.o: criaArvoreb.c
	gcc -o criaArvoreb.o -c criaArvoreb.c

printArvoreb.o: printArvoreb.c
	gcc -o printArvoreb.o -c printArvoreb.c

removeArvoreb.o: removeArvoreb.c
	gcc -o removeArvoreb.o -c removeArvoreb.c

clean:
	rm -f *.o saida
