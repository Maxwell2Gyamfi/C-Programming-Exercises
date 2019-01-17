#pragma warning(disable:4996)
#include <stdio.h>
void hexi(char n);
int main()
{
	char input = '\0';
	printf("Input a character: ");
	scanf("%c", &input);
	hexi(input);
	getch();
	return 0;
}
void hexi(char n)
{
	int flag = 0;
	char buffer[20] = { 'A','B','C','D','E','F' };

	int i = 0;
	for (i = 0;i < 5;i++)
	{
		flag = (n == buffer[i] || n > 47 && n < 58) ? 1 : 0;
		if (flag == 1) break;
	}
	flag == 1 ? printf("The entered character is a hexadecimal digit.") : printf("The entered character is not a hexadecimal digit.");
}