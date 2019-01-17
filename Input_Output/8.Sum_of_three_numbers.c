#pragma warning (disable:4996)

#include <stdio.h>


void sum(int *numbers, int *sum);
int *get_numbers();
void print_sum(int sum);


int main()
{
	int *numbers;
	int sum1;

	numbers = get_numbers();
	if (numbers != 0)
	{
		sum(numbers, &sum1);
		print_sum(sum1);
	}
	getch();
	return 0;
}
int *get_numbers()
{

	static int numbers[3];
	char c[3];
	int i = 0;

	printf("Input three numbers separated by comma: ");

	for (i = 0; i < 3; i++)
	{
		scanf("%d%c", &numbers[i], &c[i]);
		if ((c[i] == ',') || (c[2] == '\n')) {}
		else
		{
			printf("Incorrect sign");
			return 0;
		}
	}
	return numbers;

}
void sum(int *numbers, int *sum)
{
	int i = 0;
	int sum2 = 0;
	for (i = 0; i < 3; i++)
	{
		sum2 = sum2 + numbers[i];
	}
	*sum = sum2;
}
void print_sum(int sum)
{
	printf("The sum of three numbers : %d", sum);
}