#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void convert_to_Upper(char n[], int lenght);
int isalpha(char n);
void convert_to_upper(char *n);
int main()
{
	char buffer[50];

	printf("Input a string: ");

	fgets(buffer, sizeof buffer, stdin);
	convert_to_Upper(buffer, strlen(buffer));

	printf("%s", buffer);
	getch();
	return 0;
}
void convert_to_Upper(char n[],int lenght)
{
	int x = 0;
	int i = 0;
	char *k = &n[0];
	for (i = 0;i < lenght;i++)
	{
		(isalpha(n[i]) ? convert_to_upper((&k[i])) : x);
	}
}
int isalpha(char n)
{
	return (n > 64 && n < 91 || n>96 && n < 123) ? 1 : 0;
}
void convert_to_upper(char *n)
{
	int k = 0;
	*n> 96 && *n < 123 ? (*n = *n - 32) : k;
}