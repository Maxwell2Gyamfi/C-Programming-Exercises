#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int m = 29;
	int *ab = &m;

	printf("\nAddress of m : 0x%08x", &m);
	printf("\nValue of m : %d", m);
	printf("\n\nNow ab is assigned with the address of m.");
	printf("\nAddress of pointer ab : 0x%08x", ab);
	printf("\nContent of pointer ab : %d", *ab);

	m = 34;

	printf("\n\nThe value of m assigned to %d now.", m);
	printf("\nAddress of pointer ab : 0x%08x", ab);
	printf("\nContent of pointer ab : %d", *ab);

	*ab = 7;
	printf("\n\nThe pointer variable ab is assigned with the value %d now.", *ab);
	printf("\nAddress of m : 0x%08x", &m);
	printf("\nValue of m : %d", m);



	return 0;
}