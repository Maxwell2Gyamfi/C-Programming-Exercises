#pragma warning(disable:4996)
#include<stdio.h>
#include <math.h>

int get_lenght_n(int n);
int get_product(int count, int number);
void get_atrophic(int n);
int get_answer(int lenght, int n);
int get_n();

int main()
{
	int n = 0;
	n = get_n();
	
	get_atrophic(n);
	
	getch();
	return 0;
}
int get_n()
{
	int n = 0;
	printf("Enter a number : ");
	scanf("%d", &n);
	return n;
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
int get_product(int count,int number)
{
	int sum = 1;
	int i = 0;
	
	switch (count)
	{
	case 1:
		sum =get_answer(10, number);
		break;
	case 2:
		sum =get_answer(100, number);
		break;
	case 3:
		sum =get_answer(1000, number);
		break;
	case 4:
		sum =get_answer(10000, number);
		break;
	case 5:
		sum =get_answer(100000, number);
		break;
	default:
		break;
	}
	return sum;
}
int get_answer(int lenght,int n)
{
	int i = 0;
	int result = 0;

	result = n % lenght;

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
    
	if (compare == n)printf("The given number is an Automorphic Number.", n);

}