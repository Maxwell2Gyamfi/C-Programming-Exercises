#pragma warning(disable:4996)
#include <stdio.h>

int get_lcf(int first, int second, int i);
void get_numbers(int *first, int *second);
int main()
{
	
	int i = 0;
	int first, second = 0;

	get_numbers(&first, &second);
	i = first > second ? first : second;
	get_lcf(first,second,i);

	getch();

	return 0;
}
void get_numbers(int *first, int *second)
{
	printf("Input 2 numbers: ");
	scanf("%d%d", first, second);
}

int get_lcf(int first,int second,int i)
{
	int s = 0;
	if (i>first *second)
	{
		return 0;
	}
	if (i%first == 0 && i%second == 0)
	{
		printf("The lcf of %d and %d is %d", first, second, i);
		return 1;
	}
	else
	{
		s = first > second ? first : second;
		get_lcf(first, second, i+s);
	}
}
