#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_random_number();
int get_number();
void guess_number(int number, int number2);

int main()
{	
	int random_number = 0;
	int guess_number2 = 0;

	random_number = get_random_number();
	get_number(random_number);

	getch();
	return 0;
}
int get_random_number()
{
	srand(time(NULL));
	int number = rand() % 10;

	return number;

}
void guess_number(int number, int number2)
{
	if (number2 > number)
	{
		printf("The number is lower\n");
	}
	else if (number2 < number)
	{
		printf("The number is higher\n");
	}
	else
	{
		printf("That is correct\n");
	}

}
int get_number(int random_number)
{

	int number = 0;
	do {
		printf("Guess the number: ");
		scanf("%d", &number);
		guess_number(random_number,number);


	} while (number != random_number);

}