#pragma warning(disable:4996)
#include <stdio.h>
#define A 65
#define Z 90

int main()
{
	int i = 0;
	int *k = &i;

	for (i = A; i <=Z; i++)
	{
		printf("%c ", *k);
	}

	getch();
	return 0;
}
