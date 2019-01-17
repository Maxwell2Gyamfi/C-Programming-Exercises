#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
void get_kaprekar();
int get_lenght(int number);
int main()
{
	get_kaprekar();
	getch();

	return 0;
}
int get_lenght(int number)
{
	int count = 0;
	while (number)
	{
		number = number / 10;
		count++;
	}
	return count;
}
void get_kaprekar()
{
	int i = 1;int s = 0;int l = 0;int k = 0;int z = 0;int q = 0;
	int lenght = 0;int square = 0;
	char buffer[20];char firstpart[20];char secondpart[20];

	while (i < 1000)
	{
		square = i * i;
		k = square;
		lenght = get_lenght(square);

		if (square == 1)
		{
			s = 0;l = s;
		}
		else if (lenght % 2 == 0)
		{
			s = lenght / 2 - 1;
			l = s;
		}
		else
		{
			s = lenght / 2 ;
			l = s-1;
		}
		while (k)
		{
			if (s > l)q = -1;
			z = k % 10;
			if (q < lenght/2)
			{
				firstpart[s--] = z + '0';
			}
			else
			{
				secondpart[l--] = z + '0';
			}
			k = k / 10;
			q++;
		}
		q =0;
		sscanf(firstpart, "%d", &s);
		sscanf(secondpart, "%d", &l);

		if (s + l == i)printf("%d ", i);
		i++;
	}
}