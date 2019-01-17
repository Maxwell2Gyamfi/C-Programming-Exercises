#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

char *get_string();
int string_to_integer(char *name);


int main()
{
	char *name;
	int number = 0;


	name = get_string();
	number = string_to_integer(name);

	printf("The value input is %d", number);
	getch();
	return 0;
}

char *get_string()
{
	static char name[7];

	printf("Enter a string(max 6 characters): ");
	scanf("%s", name);


	return name;
}
int string_to_integer(char *name)
{
	int number = 0;

	//sscanf(name, "%d", &number);
	number = atoi(name);
	
	return number;

}
