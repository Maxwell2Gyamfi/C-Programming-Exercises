#pragma warning(disable:4996)

#include <stdio.h>

void get_numbers(int *first, int *second);
void add_numbers(int *first, int *second);

int main()
{
	int *a, *b = 0;
	int firstnumber = 0; int secondnumber = 0;
	get_numbers(&firstnumber, &secondnumber);

	a = &firstnumber;
	b = &secondnumber;

	add_numbers(a, b);

	getch();
	return 0;
}
void get_numbers(int *first, int *second)
{

	printf("Input the first number : ");
	scanf("%d", &(*first));

	printf("Input the second number : ");
	scanf("%d", &(*second));

}
void add_numbers(int *first, int *second)
{

	int sum = 0;
	sum = *first + *second;
	printf("The sum of %d and %d  is %d",*first,*second, sum);
}