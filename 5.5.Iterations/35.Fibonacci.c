#pragma warning (disable:4996)

#include <stdio.h>

int get_n(int **temp);
int fibonacci(int **numbers, int n);
void print_fibonacci(int *numbers, int n);


int main()
{
	int n = 0;
	int *numbers = 0;

	n = get_n(&numbers);
	fibonacci(&numbers, n);
	print_fibonacci(numbers, n);

	getch();
	return 0;
}
int get_n(int **temp)
{
	int n;
	printf("Input number of terms to display :");
	scanf("%d", &n);

	*temp = (int*)calloc(n, sizeof(int));

	if (*temp == 0)
	{
		fputs("Error allocating", stderr);
		exit(0);
	}
	return n;
}
int fibonacci(int **numbers,int n)
{
	int fibonacci_numbers = 0;
	int i = 0;
	
	while(fibonacci_numbers<n)
	{
		if (i == 0)
		{
			(*numbers)[i] = 0;
			fibonacci_numbers;
			
		}
		else if (i == 1)
		{
			(*numbers)[i] = 1;
			fibonacci_numbers++;
		}
		else
		{
			(*numbers)[i] = (*numbers)[i - 2] + (*numbers)[i - 1];
			fibonacci_numbers++;
		}
		i++;
	}
}
void print_fibonacci(int *numbers,int n)
{
	int i = 0;
	
	for (i = 0; i < n; i++)
	{
		printf("%d ", numbers[i]);
	}
}