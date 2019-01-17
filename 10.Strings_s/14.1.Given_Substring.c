#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
int get_substring(char *n, char *sub, int lenght1, int lengh2, int start, char *n2,int s);
int main()
{
	char temp[50];
	char substring[50];
	char string[50];

	printf("Enter a string : ");
	fgets(string, sizeof(string), stdin);
	printf("Enter the substring : ");
	fgets(substring, sizeof(substring), stdin);

	int lenght1 = strlen(string);
	int lenght2 = strlen(substring);
	substring[lenght2-1] = '\0';

	if (get_substring(string, substring, lenght1, lenght2, 0, temp,0))
	{
		printf("The substring exists in the string.");
	}
	else
	{
		printf("The substring does not exist in the string.");
	}

	getch();
	return 0;
}
int get_substring(char *n, char *sub,int lenght1,int lengh2,int start,char *n2,int s)
{
	
	int i=0;
	int k = 0;

	if (strcmp(n2, sub) == 0)
	{
		return 1;
	}
	if (start >=lenght1 )
	{
		return 0;
	}
	else
	{
		while (k < lengh2-1)
		{
			n2[k] = n[s];
			k++;
			s++;
		}
		n2[lengh2-1] = '\0';
		get_substring(n, sub, lenght1, lengh2, start + 1, n2,s+1);
	}

}
