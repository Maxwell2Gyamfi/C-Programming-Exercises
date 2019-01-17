#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int check_lenght(int n);
int get_number(int *start, int *end);
int check_strong_number(int start, int end);

int main()
{
	
	int n,start, end = 0;
	n = get_number(&start,&end);
	check_strong_number(start,end);
	
	getch();
	return 0;
}

int get_number(int *start,int *end)
{
	
	int lenght = 0;

	printf("Input starting range of number :");
	scanf("%d", &(*start));
	printf("Input ending range of number: ");
	scanf("%d", &(*end));

}
int check_lenght(int n)
{
	int digits = 0;

	do
	{
		digits++;
		n = n / 10;

	} while (n);
	return digits;
}
int check_strong_number(int start,int end)
{
	int i,j,value,l,lenght,total = 0;
	int sum = 1;

	char buffer[10];
	printf("The Strong numbers are: ");
	for (i = start; i <= end; i++)
	{
		lenght = check_lenght(i);
		itoa(i, buffer, 10);
		
		for (l = 0; l <lenght; l++)
		{
			value = buffer[l] - '0';

			for (j = 1; j <=value; j++)
			{
				sum = sum * j;
			}
			total += sum;
			sum = 1;
		}
		if (i == total) 
		{
			printf("%d ", i);
		}
		total = 0;
	}
}
