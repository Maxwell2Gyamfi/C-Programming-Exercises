#pragma warning(disable:4996)
#include <stdio.h>
int get_numberofelements();
void get_numbers(int *numbers, int number);
int get_bigger(int i, int *numbers, int number, int biggest);
int main()
{
	int biggest = 0;
	int number = 0;
	int numbers[30];

	number = get_numberofelements();
	get_numbers(numbers, number);
	biggest = get_bigger(0, numbers, number, numbers[0]);
	printf("Largest element of an array is: %d", biggest);

	getch();
	return 0;
}
int get_numberofelements()
{

	int number = 0;
	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &number);
	return number;

}
void get_numbers(int *numbers, int number)
{
	int i = 0;
	printf("Input %d elements in the array: ");
	printf("\n");
	for (i = 0; i < number; i++)
	{
		printf("Element %d : ", i);
		scanf("%d", &numbers[i]);
	}

}
int get_bigger(int i, int *numbers, int number,int biggest)
{
	if (i >= number)
	{
		return biggest;
	}
	else
	{
		biggest = numbers[i] > biggest ? numbers[i] :biggest;
		get_bigger(i+1, numbers, number, biggest);
	}


}