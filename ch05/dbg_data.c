#include <stdio.h>

int add(int i, int j)
{
	 int k;

	 k= i + j;
	 
	 return k;
}

int main()
{
	int m= 2;
	int n = 3;
	int sum;

	sum = m+n;
	printf("sum = %d\n",sum);

	sum = add(m,n);
	printf("sum=%d\n",sum);
}
