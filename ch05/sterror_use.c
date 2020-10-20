#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	FILE *f;

	if(argc < 2){
		printf("usuage: strerror_use nofliename\n");
		exit(1);
	}

	if( (f = fopen(argv[1],"r") ) == NULL ){
	       printf("cannot open a file \"%s\" ...(error msg: %s)\n",argv[1],strerror(errno));
       exit(1);
	}

	printf("open a file \"%s\".\n",argv[1]);
	fclose(f);
}	
