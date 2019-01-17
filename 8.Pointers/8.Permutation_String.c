#pragma warning(disable:4996)
#include <stdio.h>
#include<stdlib.h>

void permute(char *string, int start, int end);
void swap(char *first, char *second);
int main()
{
	int lenght = 0;
	char string1[20];

	printf("Enter the string: ");
	scanf("%s", string1);
	lenght = strlen(string1) - 1;

	permute(string1, 0, lenght);
	getch();

	return 0;
}
void permute(char *string, int start, int end)
{
	int i = 0;
	if (start == end)
	{
		printf("%s\n", string);
	}
	else
	{
		for (i = start; i <=end; i++)
		{
			swap(&string[start], &string[i]);
			permute(string, start+1, end);
			swap(&string[start], &string[i]);
		}
	}
}
void swap(char *first, char *second)
{
	char temp = 0;
	temp = *first;
	*first = *second;
	*second = temp;
}
