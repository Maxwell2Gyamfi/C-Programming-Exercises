#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
int *get_numbers();
int bubble_swap_numbers(int *numbers);
void print_bubble_sort(int *numbers);

int main()
{
	int *numbers = get_numbers();;
	bubble_swap_numbers(numbers);
	print_bubble_sort(numbers);
	getch();
	return 0;
}
int *get_numbers()
{
	static int array_numbers[6];
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &array_numbers[i]);
	}
	return array_numbers;
}
int bubble_swap_numbers(int *numbers)
{
	int first = 0;
	int last = 4;
	int i = 0;
	int temp = 0;

	/*int *p = (int*)malloc(last * sizeof(int));
	p = &numbers[0];*/

	do {
		temp = *(numbers + first);
		*(numbers + first) = *(numbers + last);
		*(numbers + last) = temp;
	
		first++;
		last--;
	} while (last / first >=1 );
}
void print_bubble_sort(int *numbers)
{
	int i = 0;

	for (i = 0; i < 5; i++)
	{
		printf("array_n[%d] = %d\n", i, numbers[i]);
	}

}