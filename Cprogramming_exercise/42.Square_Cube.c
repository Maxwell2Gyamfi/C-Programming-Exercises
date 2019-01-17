#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>

int number_of_lines();
void print_square_cube(int numbers);
void better_solution(int number);
int main()
{

	int numbers = number_of_lines();
	print_square_cube(numbers);
	better_solution(numbers);
	getch();
	return 0;
}
int number_of_lines()
{
	int numbers = 0;

	printf("Enter number of lines: ");
	scanf("%d", &numbers);

	return numbers;
}
void print_square_cube(int numbers)
{
	int i = 0;
	int j = 0;
	int counter = 1;

	for (i = 0; i < numbers; i++)
	{
		for (j = 1; j <= 3; j++)
		{
			if (j == 1)
			{
				printf("%d ", counter);
			}
			else if (j == 2)
			{
				printf("%d ",counter*counter);
			}
			else if (j == 3)
			{
				printf("%d ", counter*counter*counter);
			}
			if (j%3 == 0)
			{
				printf("\n");
			}
		}
		counter++;
	}


}
void better_solution(int number)
{
	int i = 0;
	printf("\n");
	for (i = 1; i <= number; i++)
	{
		printf("%d %d %d\n", i, i*i, i*i*i);
	}


}