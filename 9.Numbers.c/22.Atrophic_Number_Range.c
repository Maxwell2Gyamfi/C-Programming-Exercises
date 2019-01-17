#pragma warning(disable:4996)
#include<stdio.h>
#include <math.h>
int get_number();
int get_lenght_n(int n);
int get_product(int count, int number);
void get_atrophic(int n);
int get_answer(int lenght, int n);

int main()
{
	int n = 1;

	while (n < 1000)
	{
		get_atrophic(n);
		n++;
	}
	getch();
	return 0;
}
int get_lenght_n(int n)
{
	int count = 0;
	int s = n;
	while (s)
	{
		s = s / 10;
		count++;
	}
	return count;
}
int get_product(int count, int number)
{
	int sum = 1;
	int i = 0;

	switch (count)
	{
	case 1:
		sum = get_answer(10, number);
		break;
	case 2:
		sum = get_answer(100, number);
		break;
	case 3:
		sum = get_answer(1000, number);
		break;
	case 4:
		sum = get_answer(10000, number);
		break;
	case 5:
		sum = get_answer(100000, number);
		break;
	default:
		break;
	}
	return sum;
}
int get_answer(int lenght, int n)
{
	int i = 0;
	int result = 0;
	for (i = 0;i < 1;i++)
	{
		result = n % lenght;
	}
	return result;

}
void get_atrophic(int n)
{
	int square = 1;
	int compare = 0;
	int sum = 0;
	int lenght = get_lenght_n(n);
	square = pow((double)n, 2.0);
	compare = get_product(lenght, square);

	if (compare == n)printf("%d ", n);

}