#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

#define  A 96
#define Z 123
#define a 64
#define z 91

void convert_to_Lower(char n[], int lenght);
int isalpha(char n);
void convert_to_lower(char *n);

int main()
{
	char buffer[50];

	printf("Input a string: ");

	fgets(buffer, sizeof buffer, stdin);
	convert_to_Lower(buffer, strlen(buffer));

	printf("%s", buffer);
	getch();
	return 0;
}
void convert_to_Lower(char n[], int lenght)
{
	int x = 0;
	int i = 0;
	char *k = &n[0];
	for (i = 0;i < lenght;i++)
	{
		(isalpha(n[i]) ? convert_to_lower((&k[i])) : x);
	}
}
int isalpha(char n)
{
	return (n > a && n < z || n>a && n < z) ? 1 : 0;
}
void convert_to_lower(char *n)
{
	int k = 0;
	*n > a && *n < z ? (*n = *n +32) : k;
}