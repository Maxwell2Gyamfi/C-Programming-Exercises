#pragma warning(disable:4996)
#include <stdio.h>

int happy_number(int n, int counter);
void repeat(int range);

int main()
{
	int range = 1;
	repeat(range);
	getch();
	return 0;
}
void repeat(int range)
{
	while (range <= 1000)
	{
		if (happy_number(range, 0)) printf("%d ", range);
		range++;
	}
}
int happy_number(int n, int counter)
{
	int sum = 0;
	int remainder = 0;

	if (n == 1) return 1;
	if (counter == 20) return 0;
	else
	{
		while (n)
		{
			remainder = n % 10;
			n = n / 10;
			sum += remainder * remainder;
		}
		n = sum;
	}
	happy_number(n, counter + 1);
}