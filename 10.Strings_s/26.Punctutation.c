#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>
void count_puntutation(char *n);
int main()
{
	char buffer[50];
	printf("Input a string: ");
	fgets(buffer, sizeof buffer, stdin);
	count_puntutation(buffer);
	getch();
	return 0;
}
void count_puntutation(char *n)
{
	int k = 0;
	int i = 0;
	int count = 0;
	for (i = 0;i < strlen(n);i++)
	{
		ispunct(n[i]) ? count++ : k;
	}
	printf("The punctuation characters exists in the string is : %d", count);
}