#pragma warning(disable:4996)
#include <stdio.h>
int get_number();
int get_pronics(int number);
int main()
{

	int n = get_number();
	get_pronics(n);

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Enter a number : ");
	scanf("%d", &n);
	return n;
}
int get_pronics(int number)
{
	int sum = 0;
	int i = 1;
	for (i = 1;i <= number;i++)
	{
		sum = i * i + i;
		if (sum == number)
		{
			printf("%d is a pronic number", sum);
			return 1;
		}
		sum = 0;
	}
	printf("%d is not a pronic number", number);
}
