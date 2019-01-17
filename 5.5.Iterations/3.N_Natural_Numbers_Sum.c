#pragma warning(disable:4996)

#include <stdio.h>

int get_n();
int get_numbers(int n);
void get_sum(int *memory, int n);


int main()
{
	int n = 0;
	int *memory = 0;

	n = get_n();
	
	memory = get_numbers(n);
	get_sum(memory, n);

	free(memory);
	getch();
	return 0;
}
int get_n()
{
	int n = 0;
    
	printf("Test data: ");
	scanf("%d", &n);
	return n;
}
int get_numbers(int n)
{
	size_t i = 1;

	int *memory = (int*)calloc(n, sizeof(int));

	if (memory == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}
	for (i = 1; i <=n; i++)
	{
		memory[i] = i;
	}

	return memory;
}
void get_sum(int *memory, int n)
{
	int sum = 0;
	size_t i;

	printf("The first %d natural numbers is: \n",n);

	for (i = 1; i <=n; i++)
	{
		printf("%d ", memory[i]);
		if (i % 10 == 0)
		{
			printf("\n");
		}
		sum += memory[i];
	}

	printf("\nThe Sum of Natural Number up to %d terms: %d", n, sum);
}