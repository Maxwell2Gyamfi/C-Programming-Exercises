#pragma warning(disable:4996)
#include <stdio.h>
int get_number();
void get_deficient(int number);
int main()
{
	int number = 0;
	number = get_number();
	get_deficient(number);

	getch();
	return 0;
}
int get_number()
{
	int number = 0;

	printf("Input a number: ");
	scanf("%d", &number);
	return number;
}
void get_deficient(int number)
{
	int sum = 0;
	int i = 0;
	for (i = 1;i < number;i++)
	{
		if (number%i == 0)
		{
			sum += i;
		}
	}
	if (sum < number)printf("%d is a deficient number", number);
	else printf("%d is  not a deficient number", number);
}