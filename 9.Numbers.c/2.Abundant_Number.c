#pragma warning (disable:4996)
#include <stdio.h>
int get_number();
void get_abundant(int number);
int main()
{
	int number = 0;
	number = get_number();
	get_abundant(number);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;
	printf("Enter a number : ");
	scanf("%d", &number);

	return number;
}
void get_abundant(int number)
{
	int i = 0;
	int abundant = 0;

	for (i = 1;i < number;i++)
	{
		if (number%i == 0)
		{
			abundant += i;
		}
	}
	if (abundant > number)printf("\n%d is an anundant number",number);
	else printf("\n%d is not an anundant number",number);

}