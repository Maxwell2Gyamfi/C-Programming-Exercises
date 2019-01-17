#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int main()
{

	printf("The size of int is: %d bytes\n", sizeof(int));
	printf("The size of long is: %d bytes\n", sizeof(long));
	printf("The size of long long is: %d bytes\n", sizeof(long long));
	printf("The size of double is: %d bytes\n", sizeof(double));
	printf("The size of long double is: %d bytes\n", sizeof(long double));

	getch();

	return 0;
}