#pragma warning(disable:4996)

#include <stdio.h>
int isdigit(char n);
int main()
{
	char n = 0;
	printf("Input a character: ");
	scanf("%c", &n);
	isdigit(n) ? printf("The entered character is a digit.") : 
		              printf("The entered character is not a digit.");

	getch();
	return 0;
}
int isdigit(char n)
{
	int s = n - '0';
	return (s >= 0 && s <= 9) ? 1 : 0;
}
