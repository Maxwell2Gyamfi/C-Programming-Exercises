#pragma warning(disable:4996)
#include <stdio.h>
int islowercase(char n);
int isalphabet(char n);
void islower(char n);
int main()
{
	char n = '\0';
	printf("Input a character : ");
	scanf("%c", &n);
	islower(n);

	getch();
	return 0;
}
int islowercase(char n)
{
	int a = 'a';
	int z = 'z';
	return (n>=a&&n<=z )? 1 : 0;
}
int isalphabet(char n)
{
	int a = 'a';
	int z = 'z';
	int A = 'A';
	int Z = 'Z';

	return (n>=a&&n<=z || n>=A&&n<=Z) ? 1 : 0;
}
void islower(char n)
{
	int k = 0;
    isalphabet(n)?(islowercase(n)?
		printf("The entered letter is a lowercase letter."): 
		printf("The entered letter is not a lowercase letter.")):
		printf("The entered character is not an alphabet.");
}