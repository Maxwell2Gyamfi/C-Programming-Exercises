#pragma warning(disable:4996)
#include <stdio.h>

void get_numbers(int *numbers1, int *size1, int *numbers2, int *size2);
void merge_arrays(int *numbers1, int *numbers2, int size1, int size2);
void find_biggest(int *numbers, int size, int start);
void swap(int *firstnumber, int *secondnumber);
int copy_elements(int *numbers, int size, int *numbers_merged, int index);
void print_numbers_descending(int *numbers, int final_size);

int main()
{
	int size1, size2 = 0;
	int numbers1[20];
	int numbers2[20];

	get_numbers(numbers1, &size1, numbers2, &size2);

	getch();
	return 0;
}
void get_numbers(int *numbers1,int *size1, int *numbers2,int *size2)
{

	int i = 0;
	printf("Input the number of elements to be stored in the first array : ");
	scanf("%d", &(*size1));

	printf("Input %d elements in the array : ", *size1);
	printf("\n");
	for (i = 0; i < *size1; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers1[i]);
	}

	printf("\n");
	printf("Input the number of elements to be stored in the first array : ");
	scanf("%d", &(*size2));

	printf("Input %d elements in the array : ", *size2);
	printf("\n");
	for (i = 0; i < *size2; i++)
	{
		printf("element - %d : ", i + 1);
		scanf("%d", &numbers2[i]);
	}
	merge_arrays(numbers1, numbers2, *size1, *size2);
}
void merge_arrays(int *numbers1, int *numbers2, int size1, int size2)
{

	int numbers_merged[40];
	int index = 0;
	int index1 = 0;
	int final_size = 0;
	int i = 0;
	int start = 0;

	index1 = copy_elements(numbers1,size1, numbers_merged, index);
	final_size = copy_elements(numbers2, size2, numbers_merged, index1);
	find_biggest(numbers_merged, final_size, start);
	print_numbers_descending(numbers_merged, final_size);

}
void find_biggest(int *numbers, int size,int start)
{
	int i = 0;
	int j = 0;
	int bigger = 0;
	int index = 0;

		for (i = start; i < size; i++)
		{
			if (numbers[i] >= bigger)
			{
				bigger = numbers[i];
				index = i;
			}
		}
		
		if (start == size)return 1;
		swap(&numbers[index], &numbers[start]);
		find_biggest(numbers, size, start + 1);

}
void swap(int *firstnumber,int *secondnumber)
{

	int temp = 0;
	temp = *firstnumber;
	*firstnumber = *secondnumber;
	*secondnumber = temp;
}
int copy_elements(int *numbers,int size, int *numbers_merged, int index)
{
	int i = 0;
	int temp_index = 0;

	for (i = 0; i < size; i++)
	{
		numbers_merged[index++] = numbers[i];
		temp_index = index;
	}
	return temp_index;
}
void print_numbers_descending(int *numbers, int final_size)
{
	int i = 0;

	printf("\n");
	printf("The merged array in descending order : ");

	for (i = 0; i < final_size; i++)
	{
		printf("%d ", numbers[i]);
	}
}
