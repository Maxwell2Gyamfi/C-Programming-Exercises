#pragma warning(disable:4996)
#include <stdio.h>
void get_string(char *n);
int capital_letter(char *n);
int main()
{

	char n[20];
	get_string(n);
	capital_letter(n);

	getch();
	return 0;
}
void get_string(char *n)
{
	printf("Input a string including one or more capital letters: ");
	scanf("%s", n);
}
int capital_letter(char *n)
{
	char k = 'A';
	char s = 'Z';
	static int i = 0;

	if (n[i] >= k && n[i] <= s)
	{
		printf("The first capital letter that appears in the string is %c", n[i]);
		return;
	}
	if (n[i] == '\0')
	{
		printf("There is no capital letter");
		return;
	}
	else
	{
		i++;
		capital_letter(n);
	}
}