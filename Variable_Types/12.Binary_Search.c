#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

int *get_numbers(int *size);
int get_search_value();
struct response binary_search(int *numbers, int size, int value);


typedef struct response
{
	char answer[20];

}p;


int main()
{
	p m;
	int number = 0;
	int *numbers;
	int size = 0;

	numbers = get_numbers(&size);
	number = get_search_value();
	m = binary_search(numbers, size, number);
	printf("%s",m.answer);

	getch();
	return 0;
}

int *get_numbers(int *size)
{
	int i = 0;
	int array_size = 5;
	static int numbers[5];


	*size = array_size;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &numbers[i]);
	}
	return numbers;

}
struct response binary_search(int *numbers, int size, int value)
{
	int i = 0;
	int j = 0;
	char value2[3];

	p m;

	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (value == numbers[i] || value == numbers[j])
			{
				sprintf(m.answer,"%d is found", value);
				return m;
			}
		}
	}

	sprintf(m.answer, "%d is not found", value);
	return m;
}
int get_search_value()
{
	int value;
	printf("Enter a value to search: ");
	scanf("%d", &value);

	return value;

}
