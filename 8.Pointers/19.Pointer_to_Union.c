#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

typedef union employee
{
	char name[10];
}employer;


int main()
{
	employer m;
	employer *k;
	strcpy(m.name, "Jhon Mc");
	

	k = &m;
	printf("%s %s", m.name,k->name);


	getch();
	return 0;
}