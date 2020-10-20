staticout : libstatic.a
	cd ..;gcc -I./libmakefile -L./libmakefile -o staticout main.c -lstatic

add.o : add.c
	gcc -c add.c

sub.o : sub.c
	gcc -c sub.c

multi.o : multi.c
	gcc -c multi.c

divi.o : divi.c
	gcc -c divi.c

libstatic.a : add.o sub.o multi.o divi.o
	ar rcs libstatic.a add.o sub.o multi.o divi.o

clean :
	rm -f libstatic.a add.o sub.o multi.o divi.o
	cd ..;rm -f staticout	
	
