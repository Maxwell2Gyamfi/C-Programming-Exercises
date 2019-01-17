#pragma warning (disable:4996)

#include <stdio.h>
void make_decision(int sold, int price);
int get_price();
int main()
{
	get_price();

	getch();

	return 0;
}
int get_price()
{

	int price=0;
	int sold=0;

	scanf("%d%d", &price, &sold);
	make_decision(sold, price);

}
void make_decision(int sold,int price)
{
	if (sold >= price)
	{
		if (sold == price)
		{
			printf("\nYou are running in no profit no loss condition.\n");
		}
		else
		{
			printf("You can booked your profit amount: %d", sold - price);
		}
	}
	else
	{
		printf("You lost %d amount", sold - price);
	}
	
}