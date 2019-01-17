#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
int get_number();
void perfect_cube(int n);
int main()
{

	int n = get_number();
	perfect_cube(n);
	getch();

	return 0;
}
int get_number()
{
	int n = 0;
	printf("Enter a number: ");
	scanf("%d", &n);
	return n;
}
void perfect_cube(int n)
{
	int number = 0;
	int flag = 0;
	int check = 0;
	int i = 0;
	for (i = 1;i < n;i++)
	{
		if (n%i == 0)
		{
			check = pow((double)i, 3);
			if (check == n)
			{
				number = i;
				flag = 1;
				break;
			}
		}
	}
	if (flag == 1)
	{
		printf("The number is a perfect Cube of %d", number);
	}
	else
	{
		printf("The number is not a perfect Cube");
	}

}
