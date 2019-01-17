#pragma warning(disable:4996)

#include <stdio.h>
int main()
{
	int m = 300;
	float fx = 300.600006;
	char cht = 'z';

	printf("Pointer : Demonstrate the use of & and * operator :  ");
	printf("\n-------------------------------------------------------- ");

	printf("\nUsing & operator : ");
	printf("\n----------------------- ");

	printf("\nAddress of m = 0x%08x", &m);
	printf("\nAddress of fx = 0x%08x", &fx);
	printf("\nAddress of cht = 0x%08x", &cht);


	printf("\nUsing & and * operator : ");
	printf("\n----------------------- ");

	printf("\nValue at address of m = %d",m);
	printf("\nValue at address of fx = %f", fx);
	printf("\nValue at address of cht = %c", cht);

	printf("\nUsing only pointer operator");
	printf("\n---------------------------- ");

	int *s = &m;
	printf("\nValue at address of m = %d", *s);
	
	float *k = &fx;
	printf("\nValue at address of fx = %f", *k);

	char *x = &cht;
	printf("\nValue at address of cht = %c", *x);

	getch();
	return 0;
}