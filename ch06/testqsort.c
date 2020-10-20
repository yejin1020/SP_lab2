#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#define TABLESIZE 5

int table[TABLESIZE] = {4,2,1,5,3};

int compare(const void *ap, const void *bp)
{
	return ( *(int *)ap - *(int *)bp);
}

int main()
{
	int i;

	qsort(table, TABLESIZE, sizeof(int), compare);
	for( i = 0; i<TABLESIZE; i++)
		printf("%d", table[i]);
	printf("\n");
}
