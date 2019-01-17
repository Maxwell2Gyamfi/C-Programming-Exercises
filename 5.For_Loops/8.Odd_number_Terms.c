#pragma warning(disable:4996)

#include <math.h>
#include <stdio.h>

void get_odd_number_terms(int n);
int get_n();
int main()
{
	
	get_n();
	getch();

	return 0;
}
int get_n()
{
	int n = 0;

	printf("Input number of terms :");
	scanf("%d", &n);

	get_odd_number_terms(n);
}
void get_odd_number_terms(int n)
{
	int sum = 0;
	int odd = 0;
	int i = 0;

	while (odd <n)
	{
		i++;
		if (i % 2 != 0)
		{
			odd++;
			printf("%d ", i);
			sum += i;
		}
	}
	printf("\nThe sum of odd Natural Numbers up to %d is %d", n, sum);


}