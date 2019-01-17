#pragma warning(disable:4996)
#include <string.h>
#include <stdio.h>


void get_string(char *name);
void get_reverse(char name[], int lenght);
void print(char *name);


int main()
{
	int lenght = 0;
	char name[20];

	get_string(name);
	lenght = strlen(name);
	get_reverse(name, lenght);
	print(name);
	getch();

	return 0;
}
void get_string(char *name)
{
	printf("Input a string : ");
	scanf("%s", name);
}
void get_reverse(char names[],int lenght)
{
	int counter = 0;
	int i = 0;
	char temp = 0;

	lenght = lenght - 1;
	char *name = &names[0];

	for (i = 0; i <=lenght; i++)
	{
		temp = name[i];
		name[i] = name[lenght];
		name[lenght] = temp;
		lenght--;
	}	
}
void print(char *name)
{
	printf("Reverse of a string is %s", name);
}