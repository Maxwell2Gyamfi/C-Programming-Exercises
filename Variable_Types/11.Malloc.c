#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int get_array_size();
int *allocate_memory(int size);
int get_array_numbers(int size, int *memory);
void print_array_numbers(int *memory, int size);

int main()
{
	int size = 0;
	int *memory;


	size = get_array_size();
	memory = allocate_memory(size);
	get_array_numbers(size, memory);
	print_array_numbers(memory, size);

	free(memory);
	getch();
	return 0;
}
int *allocate_memory(int size)
{
	
	int *memory;
	memory = (int*)malloc(size * sizeof(int));

	if (memory == NULL)
	{
		printf("Error allocating");
		exit(1);
	}

	return memory;

}

int get_array_size()
{
	int number = 0;
	printf("Enter the number of elements to be stored in array: ");
	scanf("%d", &number);

	return number;
}
int get_array_numbers(int size, int *memory)
{
	int i = 0;
	
	printf("Input 5 elements in array: ");
	for (i = 0; i < size; i++)
	{
		scanf("%d", &(*(memory + i)));
	}

}
void print_array_numbers(int *memory,int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", memory[i]);
	}

}