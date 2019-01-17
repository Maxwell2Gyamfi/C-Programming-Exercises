#pragma warning(disable:4996)

#include <stdio.h>

int get_position();
int get_numbers(int *numbers, int *size);
void insert_value(int *numbers, int *size);
void print(int *numbers, int size);

int main()
{
	int numbers[20];
	int size = 0;

	get_numbers(numbers, &size);
	insert_value(numbers, &size);

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
void insert_value(int numbers[], int *size)
{
	int i = 0;
	int temp = 0;
	int new_value = 0;
	int position = 0;
	int s = 0;
	

	printf("Input the value to be inserted : ");
	scanf("%d", &new_value);
	position = get_position();
	
	*size = *size + 1;
	s = *size - 1;

	numbers[s] = new_value;

	while (s >= position)
	{
		temp = numbers[s];
		numbers[s] = numbers[s - 1];
		numbers[s - 1] = temp;

		s--;
	}

	print(numbers, *size);
}
void print(int *numbers, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}
int get_position()
{
	int n = 0;
	printf("Enter the position,where the value to be inserted: ");
	scanf("%d", &n);

	return n;
}