#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isplaindrome(char *n, int start, int end);
char *get_string();
int main()
{
	int end = 0;
	char *s = get_string();
	end = strlen(s);
	s[end - 1] = '\0';
	isplaindrome(s, 0, end - 2);
	getch();
	return 0;
}
char *get_string()
{

	char *s = (char*)malloc(20 * sizeof(char));

	if (s == NULL)
	{
		printf("Error allocating");
		exit(0);
	}
	printf("Input any word to check if is palindrome: ");
	fgets(s, 20, stdin);

	return s;
}
int isplaindrome(char *n, int start, int end)
{
	if (start > end)
	{
		printf("The word %s is a palindrome", n);
		return 1;
	}
	if (n[start] != n[end])
	{
		printf("The word %s is not a palindrome",n);
		return 0;
	}
	else
	{
		isplaindrome(n, start + 1, end - 1);
	}
}