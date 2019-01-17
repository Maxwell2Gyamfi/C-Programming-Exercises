#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * get_string();
double convert_string(char *string);

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
double convert_string(char *string)
{
	double result;
	char local_variable[5];
	strcpy(local_variable, string);
	
	sscanf(local_variable, "%lf", &result);

	printf("%.1lf", result);
}