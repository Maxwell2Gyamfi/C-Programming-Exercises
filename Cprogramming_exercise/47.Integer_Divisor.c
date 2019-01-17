#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_divisor_part2(int size, int *numbers);
int *get_divisor(int number);
int get_number();

int main()
{
	int the_number = 0;
	int *numbers;
	

	the_number= get_number();
	numbers = get_divisor(the_number);

	get_divisor_part2(the_number, numbers);
	getch();
	return 0;
}
int get_number()
{
	int number = 0;

	printf("Enter number: ");
	scanf("%d", &number);

	return number;

}
int *get_divisor(int number)
{
	int i = 0;
	static int numbers[40];

	for (i = 1; i <= number; i++)
	{
		if (number%i == 0)
		{
			numbers[i] = i;
		}
		else
		{
			numbers[i] = 0;
		}
	}
	return numbers;
}
void get_divisor_part2(int size,int *numbers)
{
	int i = 0;

	for (i = 0; i <= size; i++)
	{
		if(numbers[i]<=0){}
		else
		{
			printf("%d ", numbers[i]);
		}
	}
}