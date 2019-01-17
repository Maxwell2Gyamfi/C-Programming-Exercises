#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void anagram(char *first, char *second);
int sort_anagram(char *first, int lenght, char *temp);

int main()
{
	char first[20];
	char second[20];

	printf("Input first string : ");
	scanf("%s", first);
	printf("Input second string : ");
	scanf("%s", second);

	anagram(first, second);
	
	getch();
	return 0;
}
void anagram(char *first, char *second)
{
	char temp2[20];
	char temp[20];
	int lenght1, lenght2 = 0;

	lenght1 = strlen(first);
	lenght2 = strlen(second);

	lenght1 == lenght2 ? (sort_anagram(first, lenght1, temp),
		sort_anagram(second, lenght1, temp2)) : 0;

	strcmp(temp, temp2) == 0 ? printf("%s and %s are anagram", first, second) :
		printf("%s and %s are not anagram", first, second);
}
int sort_anagram(char *first,int lenght,char *temp)
{
	int i = 0;
	int j = 0;
	char temp1 = '\0';
	strcpy(temp, first);

	for (i = 0; i < lenght-1; i++)
	{
		for (j = i+1; j < lenght; j++)
		{
			if (temp[i] > temp[j])
			{
				temp1 = temp[i];
				temp[i] = temp[j];
				temp[j] = temp1;
			}
		}
	}
}