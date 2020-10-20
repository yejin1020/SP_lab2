staticout : 
	cd libmakefile;make;
	cd ..;
	gcc -I./libmakefile -L./libmakefile -o staticout main.c -lstatic

clean :
	cd libmakefile;make clean;
	cd ..;rm -f staticout	
	
