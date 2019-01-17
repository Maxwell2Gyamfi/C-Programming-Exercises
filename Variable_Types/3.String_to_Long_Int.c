#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * get_string();
long int convert_string(char *string);

int main()
{
	char * name;
	name = get_string();
	convert_string(name);

	getch();
	return 0;
}
char * get_string()
{
	static char string[5];

	scanf("%s", string);

	return string;
}
long int convert_string(char *string)
{
	long int result;
	char *ptr;
	char local_variable[5];
	strcpy(local_variable, string);

	result = strtol(local_variable,&ptr,10);

	printf("%ld", result);
}