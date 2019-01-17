#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void concatenate(char *n, char *n2, int lenght1, int lenght2);

int main()
{
	char first_string[50];
	char second_string[50];

	printf("Enter first string : ");
	fgets(first_string, sizeof first_string, stdin);
	printf("Enter second string : ");
	fgets(second_string, sizeof second_string, stdin);
	concatenate(first_string, second_string, strlen(first_string), strlen(second_string));
	printf("%s", first_string);
	getch();
	return 0;
}
void concatenate(char *n, char *n2,int lenght1,int lenght2)
{
	int k = 0;
	char temp[50];

	int i = 0;
	for (i = 0;i < lenght1;i++)
	{
		temp[i] = n[i];
	}
	temp[i] = '\0';
	k = i;
	temp[k-1] = ' ';
	
	for (i = 0;i < lenght2;i++)
	{
		temp[k] = n2[i];
		k++;
	}
	temp[k] = '\0';
	strcpy(n, temp);
	
}