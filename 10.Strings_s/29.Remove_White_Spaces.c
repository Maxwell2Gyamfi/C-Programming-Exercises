#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void remove_white_spaces(char *s, int lenght);
int main()
{
	char string[50];
	printf("Input a string: ");
	fgets(string, sizeof string, stdin);
	int lenght = strlen(string);
	remove_white_spaces(string, lenght);
	getch();
	return 0;
}
void remove_white_spaces(char *s,int lenght)
{
	char *n =&s[0];
	char temp = '\0';
	int k = 0;
	int i = 0;

	for (i = 0;i < lenght;i++)
	{
		if (n[i] == ' ')
		{
			k = i;
			while (k<lenght)
			{
				temp = n[k];
				n[k] = n[k + 1];
				n[k + 1] = temp;
				k++;
			}
			lenght --;
		}
	}
	printf("%s", s);
}