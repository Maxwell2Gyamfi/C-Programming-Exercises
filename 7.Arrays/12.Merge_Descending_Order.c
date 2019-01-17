#pragma warning(disable:4996)

#include <stdio.h>

int get_numbers(int *numbers, int *size);
int descending_order_insertion(int *numbers, int size);

int main()
{
	int numbers[20];
	int size = 0;

	get_numbers(numbers, &size);
	descending_order_insertion(numbers, size);

	getch();
	return 0;
}
int get_numbers(int *numbers, int *size)
{
	int n = 0;
	int i = 0;

	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &n);

	printf("Input %d elements in the array : ", n);
	printf("\n");

	for (i = 0; i <n; i++)
	{
		printf("element - %d : ", i);
		scanf("%d", &numbers[i]);
	}
	*size = n;

}
int descending_order_insertion(int *numbers, int size)
{
	int j = 0;

	int temp = 0;
	int i = 0;

	for (i = size - 1; i >= 0; i--)
	{
		temp = numbers[i];
		j = i + 1;

		while (temp < numbers[j] && j >= 0)
		{
			numbers[j - 1] = numbers[j];
			j++;
		}
		numbers[j - 1] = temp;
	}

	printf("Elements of the array in sorted descending order: ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}