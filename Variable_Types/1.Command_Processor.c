#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	int i = 0;
	printf("Is command processor available?");
	if (system(NULL))
	{
		printf("Command processor available!\n");
	}
	else
	{
		printf("Command processor not available!\n");
		exit(1);
	}
	i = system("dir");
	printf("Returned values is %d", i);
	getch();
	return 0;
}