#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void replace(char *n, int lenght, char w);
int main()
{

	char character = '\0';
	char string[30];

	printf("Input a string: ");
	fgets(string, sizeof string, stdin);
	printf("Input replace character : ");
	scanf("%c", &character);
	replace(string, strlen(string), character);
	printf("After replacing the space with  * the new string is : %s", string);
	getch();
	return 0;
}
void replace(char *n,int lenght,char w)
{
	int s = 0;
	int i = 0;
	char *k = &n[0];

	for (i = 0;i < lenght;i++)
	{
		if (n[i] == ' ')
		{
			k[i] = w;
		}
	}

}