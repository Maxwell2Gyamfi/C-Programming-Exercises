#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_strings(char *n, char *k);
void compare(char *n, char *k);
int get_lenght(char *n);

int main()
{
	char k[50];
	char s[50];

	get_strings(k, s);
	compare(s, k);
	getch();

	return 0;
}
void get_strings(char *n, char *k)
{
	char buffer[50];
	printf("Input first string : ");
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(n, buffer);

	printf("Input second string : ");
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(k, buffer);
}
void compare(char *n, char *k)
{
	int flag = 0;
	int size = 0;
	int i = 0;
	int sizen = get_lenght(n);
	int sizek = get_lenght(k);

	if (sizen > sizek) size = sizen;
	else size = sizek;

	for (i = 0;i < size;i++)
	{
		if (n[i] != k[i])
		{
			flag = 1;
			break;
		}

	}
	printf("\n");
	if (flag == 0 && sizek == sizen)
	{
		printf("The length of both strings are equal and also both strings are equal.");

	}
	else
	{
		if (sizek == sizen)
		{
			printf("The length of both strings are equal but the strings are not equal");
		}
		else
		{
			printf("The length of both strings are not equal and also both strings are not equal.");
		}
	}
}
int get_lenght(char *n)
{
	int i = 0;
	int lenght = 0;
	while (n[i] != '\n')
	{
		i++;
	}
	return i;
}