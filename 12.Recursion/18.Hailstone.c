#pragma warning (disable:4996)
#include <stdio.h>
int main()
{
	int count = 0;
	int n = 0;
	n = get_n();

	n > 0 ? printf("The hailstone sequence starting at %d is : ", n), hailsatone(n, 0) :
		printf("The number must be positive");

	getch();
	return 0;
}
int get_n()
{
	int n = 0;
	printf("Input a postive number: ");
	scanf("%d", &n);
	return n;

}
int hailsatone(int n,int count)
{

	if (n ==1)
	{
		count++;
		printf("%d", n);
		printf("\nThe lenght of the sequence is %d", count);
		return;
	}
	else
	{
		if (n % 2 != 0)
		{
			printf("%d ", n);
			n = (3 * n) + 1;
		}
		else
		{
			printf("%d ", n);
			n = n / 2;
		}
		hailsatone(n, count + 1);
	}

}