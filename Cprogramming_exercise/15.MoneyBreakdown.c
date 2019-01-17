#pragma warning(disable:4996)

#include <stdio.h>
#include <math.h>
void breakdown(int amount);
void breakdown2(int amount);
int main()
{
	int amount = 0;
	printf("Enter amount ");
	scanf("%d", &amount);

	breakdown(amount);
	breakdown2(amount);
	getch();
	return 0;
}

void breakdown(int amount)
{

	int hun = 0;;
	int fif = 0;
	int twe = 0;
	int ten = 0;
	int fiv = 0;
	int two = 0;
	int one = 0;

	do
	{
		if (amount >= 100)
		{

			amount = amount - 100;
			hun++;
		}
		else if (amount >= 50 && amount < 100)
		{
			amount = amount - 50;
			fif++;
		}
		else if (amount >= 20 && amount < 50)
		{
			amount = amount - 20;
			twe++;
		}
		else if (amount >= 10 && amount < 20)
		{
			amount = amount - 10;
			ten++;
		}
		else if (amount >= 5 && amount < 10)
		{
			amount = amount - 5;
			fiv++;
		}
		else if (amount >= 2 && amount < 5)
		{
			amount = amount - 2;
			two++;
		}
		else if (amount >= 1 && amount < 2)
		{
			amount = amount - 1;
			one++;
		}
	} while (amount >0);

	printf("%d %d %d %d %d %d %d\n", hun, fif, twe, ten, fiv, two, one);

}
void breakdown2(int amount)
{
	

	int hun = amount / 100;
	int fif = amount % 100 / 50;
	int twen = amount % 100 % 50 / 20;
	int ten = amount % 100 % 50 % 20 / 10;
	int fiv = amount % 100 % 50 % 20 % 10/5;
	int two = amount % 100 % 50 % 20 % 10 % 5/2;
	int one = amount % 100 % 50 % 20 % 10 % 5 % 2/1;

	printf("%d %d %d %d %d %d %d", hun, fif, twen, ten, fiv, two, one);

}




