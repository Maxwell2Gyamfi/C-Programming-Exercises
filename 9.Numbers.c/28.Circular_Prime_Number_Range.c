#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void save_number(int *number, int lenght, int n);
void circular_prime(int n[], int lenght);
int get_number();
int get_lenght(int n);
int isprime_numbers(int n);

int main()
{
	int n = 1;
	int lenght = 0;
	int *numbers = NULL;

	while (n <= 1000)
	{
		lenght = get_lenght(n);
		numbers = (int*)calloc(lenght, sizeof(int));
		save_number(numbers, lenght, n);
		circular_prime(numbers, lenght);
		n++;
	}

	getch();
	return 0;
}
int get_number()
{
	int n = 0;
	printf("Input the number : ");
	scanf("%d", &n);
	return n;

}
int get_lenght(int n)
{
	int count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return count;
}
void save_number(int *number, int lenght, int n)
{
	int i = 0;
	for (i = lenght - 1;i >= 0;i--)
	{
		number[i] = n % 10;
		n = n / 10;
	}
}
void circular_prime(int n[], int lenght)
{
	int flag = 0;
	int temp = 0;
	int i = 0;
	int j = 0;
	int number = 0;
	int number2 = 0;

	for (j = 0;j < lenght;j++)
	{
		for (i = 0;i < lenght - 1;i++)
		{
			temp = n[i];
			n[i] = n[i + 1];
			n[i + 1] = temp;
		}
		number = get_integer(n, lenght, number, 0);
		if (!isprime_numbers(number))
		{
			flag = 1;
			break;
		}
		if (j == lenght - 1)
		{
			number2 = number;
		}
		number = 0;
	}
	if (flag == 0)
	{
		printf("%d ", number2);
	}

}
int get_integer(int *n, int lenght, int sum, int n1)
{
	int sum1 = 0;
	if (lenght == 0)
	{
		sum1 = sum;
		return sum1;
	}
	else
	{
		switch (lenght)
		{
		case 1:
			sum = loop(n, lenght, 1, n1, sum);
			break;
		case 2:
			sum = loop(n, lenght, 10, n1, sum);
			break;
		case 3:
			sum = loop(n, lenght, 100, n1, sum);
			break;
		case 4:
			sum = loop(n, lenght, 1000, n1, sum);
			break;
		case 5:
			sum = loop(n, lenght, 10000, n1, sum);
			break;
		case 6:
			sum = loop(n, lenght, 100000, n1, sum);
			break;
		case 7:
			sum = loop(n, lenght, 1000000, n1, sum);
			break;
			{
		default:
			break;
			}
		}
		get_integer(n, lenght - 1, sum, n1 + 1);
	}
}
int loop(int *n, int lenght, int lenght1, int n1, int sum)
{
	int sum1 = 0;
	int number = 0;
	int  i = 0;

	sum += (n[n1] * lenght1);
	sum1 = sum;
	return sum1;
}
int isprime_numbers(int n)
{
	int i = 0;
	int j = 0;
	int prime = 0;

	for (i = 1;i <= n;i++)
	{
		if (n%i == 0)
		{
			prime++;
		}
	}
	if (prime == 2)
	{
		return 1;
	}
	return 0;
}

