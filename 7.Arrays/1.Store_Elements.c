#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int i = 0;
int get_array_elements(int *numbers);
void print_numbers(int *n);
void get_array_elements2(int *numbers);

int main()
{
	int numbers[20];
	//get_array_elements(numbers);
	get_array_elements2(numbers);
	print_numbers(numbers);

	getch();
	return 0;
}
int get_array_elements(int *numbers)
{
	printf("Input 10 elements in the array: ");
	printf("\n");

	for (i = 0; i < 10; i++)
	{
		printf("Element - %d : ", i+1);
		scanf("%d", &numbers[i]);
	}
}
void print_numbers(int *n)
{
	printf("\nElements in array are: ");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", n[i]);
	}
}
void get_array_elements2(int *numbers)
{
	time_t k;
	srand(time(0));

	for (i = 0; i < 10; i++)
	{
		numbers[i] = rand() % 100;
		printf("Element - %d : %d", i + 1, numbers[i]);
		printf("\n");
	}
}
