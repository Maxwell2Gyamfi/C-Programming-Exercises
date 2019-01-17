#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_bigger_smaller(char *n, int lenght);
int main()
{
	char word[50];
	printf("Input the string : ");
	fgets(word, sizeof word, stdin);
	int lenght = strlen(word);
	get_bigger_smaller(word, lenght);

	getch();
	return 0;
}
void get_bigger_smaller(char *n,int lenght)
{
	char temp3[50];
	char smaller[50];
	char bigger[50];
	int lenght3, lenght1, lenght2 = 0;
	int i = 0;
	int k = 0;

	memset(bigger, '1', 1);
	memset(smaller, '2', 40);
	bigger[1] = '\0';
	smaller[40] = '\0';

	while (n[i] != '\n')
	{
		while (n[i] != ' ')
		{
			if (n[i] == '\n') break;
			temp3[k++] = n[i++];
		}
		temp3[k] = '\0';
	
		lenght1 = strlen(smaller);
		lenght2 = strlen(bigger);
		lenght3 = strlen(temp3);

		if (lenght3 < lenght1)strcpy(smaller, temp3);
		if (lenght3 > lenght2)strcpy(bigger, temp3);
		if (n[i] == '\n')
		{
			break;
		}
		i++;
		k = 0;
	}
	printf("The largest word is '%s' and the smallest word is '%s' int the string : %s ", bigger, smaller, n);
}
