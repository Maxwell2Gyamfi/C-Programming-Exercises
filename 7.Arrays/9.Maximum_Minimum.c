#pragma warning(disable:4996)

#include <stdio.h>
int get_numbers(int *numbers);
void find_maximum_minimum(int *numbers, int size);

int main()
{
	int numbers[20];

	get_numbers(numbers);

	getch();
	return 0;
}
int get_numbers(int *numbers)
{
	int n = 0;
	int i = 0;
    
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);

	printf("Input %d elements in the array : ", n);
	printf("\n");

	for (i = 0; i < n; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
	}
	find_maximum_minimum(numbers, n);

}
void find_maximum_minimum(int *numbers, int size)
{
	int i = 0;
	int smaller = numbers[0];
	int bigger = numbers[0];

	for (i = 0; i < size; i++)
	{
		if (numbers[i] >= bigger)bigger = numbers[i];
		if (numbers[i] <= smaller)smaller = numbers[i];
	}

	printf("\n");
	printf("Maximum element is : %d\n", bigger);
	printf("Mimimum element is : %d", smaller);
}