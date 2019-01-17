#pragma warning(disable:4996)
#include <stdio.h>
void get_lucas_numbers();
int main()
{

	get_lucas_numbers();
	getch();

	return 0;
}
void get_lucas_numbers()
{
	int count = 0;
	int start = 2; int end = 1; int sum = 0;

	while (count < 10)
	{
		if (count == 0) printf("%d ", start);
		else if (count == 1) printf("%d ", end);
		else
		{
			sum = start + end;
			start = end;
			end = sum;
			printf("%d ", sum);
		}
		count++;
	}
}