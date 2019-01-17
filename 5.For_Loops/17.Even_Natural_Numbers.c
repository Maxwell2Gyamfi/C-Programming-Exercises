#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

void printf_even_numbers(int *numbers, int n);
int get_n();
int get_numbers(int **numbers, int n);

int main()
{
	int size = 0;
	int n = 0;
	int *numbers;

	n = get_n();
	get_numbers(&numbers,n);

	printf_even_numbers(numbers,n);

	free(numbers);
	getch();
	return 0;
}
int get_n()
{
	int n = 0;
	printf("Enter amount of even numbers: ");
	scanf("%d", &n);
	return n;

}
int get_numbers(int **numbers,int n)
{
	int i = 0;
	int even = 0;


	*numbers = (int*)calloc(n, sizeof(int));
	if (*numbers == NULL)
	{
		fputs("Error allocating memory",stderr);
		exit(0);
	}
	while (even < n)
	{
		i++;
		if (i % 2 == 0)
		{
			(*numbers)[even] = i;
			even++;
		}
	}
}
void printf_even_numbers(int *numbers, int n)
{

	int i = 0;
	int sum = 0;

	printf("The even numbers are: ");

	for (i = 0; i <n; i++)
	{
		printf("%d ", numbers[i]);
		sum += numbers[i];

	}
	printf("\nThe sum of even numbers up to %d is %d", n, sum);

}
