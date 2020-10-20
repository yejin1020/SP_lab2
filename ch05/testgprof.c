#include <stdio.h>

void sub1 (void);
void sub2 (void);

int main()
{
	int i;
	for ( i = 0; i < 1000; i++) sub1();
	for ( i = 0; i < 1000; i++) sub2();
}

void sub1( void)
{
	int i;
	for( i = 0; i<1000 ; i++) sub2();
}

void sub2 (void)
{
	int j,i;
	for( i = j = 0; i<1000; i++) j++;
}
