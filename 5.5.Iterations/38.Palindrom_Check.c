#pragma warning (disable:4996)

#include <string.h>
#include <stdio.h>

int get_number();
int get_reverse(int n);
char_palindrome(int n);
int check_palindrome(char *n, int lenght);

int main()
{
	int n = 0;
	n = get_number();
	char_palindrome(n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input the number: ");
	scanf("%d", &n);

	return n;
}
char_palindrome(int n)
{
	int lenght;
	char buffer[10];

	sprintf(buffer, "%d", n);
	lenght = strlen(buffer);

	check_palindrome(buffer, lenght);

}
int check_palindrome(char *n,int lenght)
{
	int s = lenght;
	int notpalindrome = 0;
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if(n[i]==n[s-1]){}
		else
		{
			printf("%s is not a palindrome", n);
			return 0;
		}
		s--;	
	}
	printf("%s is a palindrome", n);
}