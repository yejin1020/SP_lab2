#include <stdio.h>

int my_sum(int k)
{
	int i;
	int sum = 0;

	for(i=0; i<=k; i++)
		sum += i;

	return sum;
}

