#pragma warning(disable:4996)
#include <stdio.h>

int main()
{

	char name[30];
	printf("Input a string : ");
	fgets(name, sizeof(name), stdin);
	printf("The string you eneterd is %s", name);

	getch();
	return 0;
}