#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int m = 10;
	int n, o = 0;
	int *z = 0;
	z = &m;

	printf("Here is m = %d, n and o are two integer variable and *z is an integer ", m);
	printf("\nz stores the address of m  = 0x%08x", z);
	printf("\n*z stores the value of m = %d", *z);
	printf("\n&m is the address of m = 0x%08x", &m);
	printf("\n&n stores the address of n =0x%08x", &n);
	printf("\n&n stores the address of o = 0x%08x", &o);
	printf("\n&z stores the address of z = 0x%08x", &z);

	getch();
	return 0;
}