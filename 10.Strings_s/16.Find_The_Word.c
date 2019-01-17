#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_word(char *n, int lenght, char *temp, int start, int count);
int main()
{
	int start = 0;
	int count = 0;
	int lenght = 0;
	char string[80];
	char temp[80];

	printf("Input the string: ");
	fgets(string, sizeof(string), stdin);
	lenght = strlen(string);
    count = get_word(string,lenght, temp, start, count);
	printf("The frequency of the word \"the\" is : %d ", count);
	getch();
	return 0;
}
int get_word(char *n,int lenght,char *temp,int start,int count)
{
	int i = 0;
	int k = start;
	if (n[start-1]=='\n')
	{
		return count;
	}
	else
	{
		if (strcmp(temp, "the") == 0)
		{
			count = count + 1;
		}
		while (n[k] != ' ')
		{
			if (n[k] == 'T')
			{
				n[k] = 't';
			}
			if (n[k] == '\n')
			{
				break;
			}
			temp[i] = n[k];
			i++;
			k++;
		}
		temp[i] = '\0';
		start = k+1;
		get_word(n,lenght, temp, start, count);
	}
}