#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>

int get_narcissistic(int number);
int get_lenght(int number);

int main()
{
	int number = 1;
	int count = 0;
	int result = 0;

	while(count<15)
	{
		result = get_narcissistic(number);
		if (result == 1)
		{
			printf("%d ", number);
			count++;
		}
		number++;
	}
	getch();
	return 0;
}
int get_lenght(int number)
{
	int k = number;
	int count = 0;
	while (k)
	{
		k = k / 10;
		count++;
	}
	return count;
}

int get_narcissistic(int number)
{
	int flag = 0;
	long int l = 0;
	long int sum = 0;
	int lenght = get_lenght(number);
	int s = number;

	while (s)
	{
		l = s % 10;
		sum += pow((double)l, (double)lenght);
		s = s / 10;
	}
	if (sum == number) return 1;
	else return 0;

}
