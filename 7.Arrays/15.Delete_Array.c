#pragma warning (disable:4996)
#include <stdio.h>

int get_position();
void print(int *numbers, int size);
void delete_array(int *numbers, int *size);
int get_numbers(int *numbers, int *size);

int main()
{
	int numbers[20];
	int size = 0;

	get_numbers(numbers, &size);
	delete_array(numbers, &size);

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
		printf("element - %d : ", i+1);
		scanf("%d", &numbers[i]);
	}
	*size = n;

}
void delete_array(int *numbers, int *size)
{
	int k = get_position();
	int i = 0;
	int temp = 0;

	if (k < 1 || k > size) printf("Position doesnt exist");
	
	else
	{
		while (k <= *size)
		{
			temp = numbers[k];
			numbers[k] = numbers[k + 1];
			numbers[k + 1] = temp;

			k++;
		}
		*size = *size - 1;
		print(numbers, *size);
	}
}
int get_position()
{
	int n = 0;
	printf("Input the position where to delete: ");
	scanf("%d", &n);

	return n-1;
}
void print(int *numbers, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", numbers[i]);
	}
}