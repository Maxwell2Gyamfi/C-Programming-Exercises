#pragma warning(disable:4996)
#include <stdio.h>
#define A 64
#define Z 91
int isupper(char n);
void check_upper(char n);
int main()
{
	char n = '\0';
	printf("Input a character : ");
	scanf("%c", &n);
	check_upper(n);

	getch();
	return 0;
}
int isupper(char n)
{
	return (n > A && n < Z) ? 1 : 0;
}
void check_upper(char n)
{
	isupper(n) ? printf("The entered letter is an UPPERCASE letter."):
		               printf("The entered letter is not an UPPERCASE letter.");

}