#pragma warning (disable:4996)

#include <stdio.h>
#include <ctype.h>

int sum(int firstnumber, int secondnumber);
void sum_integers(int firstnumber, int secondnumber);

void jim_calculator();
void calculator();
char get_yes_or_no();
int firstnumber = 0;
int secondnumber = 0;
int main()
{
	
	//calculator();
	jim_calculator();

	getch();

	return 0;
}
int sum(int firstnumber, int secondnumber)
{

	int result = 0;

	result = firstnumber + secondnumber;

	return result;
}
void sum_integers(int firstnumber, int secondnumber)
{
	int result = firstnumber + secondnumber;
	printf("%d\n", result);

}
void calculator()
{
	char choice;
	int result = 0;
	char repeat = 0;

			do
			{
				printf("Enter first number, operator(+-*/) and second number: \n");
				scanf("%d %c %d", &firstnumber, &choice, &secondnumber);

				switch (choice)
				{
				case '+':
					result = firstnumber + secondnumber;
					printf("%d\n", result);
					break;
				case '-':
					result = firstnumber - secondnumber;
					printf("%d\n", result);
					break;
				case '*':
					result = firstnumber * secondnumber;
					printf("%d\n", result);
					break;
				case '/':
					result = firstnumber / secondnumber;
					printf("%d\n", result);
					break;
				}
				printf("Would you like to repeat: \n");
			    repeat = get_yes_or_no();

			} while ((repeat == 'Y') || (repeat == 'y'));
}
void jim_calculator()
{

	char choice;
	int result = 0;
	char repeat = 0;
	char input;
	char inputi[256];
	int itemread = 0;
	

		printf("Enter first number, operator(+-*/) and second number: \n");
		scanf("%d %c %d", &firstnumber, &choice, &secondnumber);

		switch (choice)
		{
		case '+':
			result = firstnumber + secondnumber;
			printf("%d\n", result);
			break;
		case '-':
			result = firstnumber - secondnumber;
			printf("%d\n", result);
			break;
		case '*':
			result = firstnumber * secondnumber;
			printf("%d\n", result);
			break;
		case '/':
			result = firstnumber / secondnumber;
			printf("%d\n", result);
			break;
		}
		
		do
		{

			itemread = scanf(" %s", inputi);

			if (itemread != 1)
			{
				printf("quitting becuase something went wrong reading from the keyboard\n");

				return(0);
			}

			else
			{
				
				switch (inputi[0])
				{
				case 'p':

					scanf(" %c %d", &choice, &secondnumber);
					if (choice == '+')
					{
						result = result + secondnumber;
						printf("%d\n", result);
					}
					else if (choice == '-')
					{
						result = result - secondnumber;
						printf("%d\n", result);
					}
					else
					{
						printf("wrong input");
					}
					break;
				case 'q':
					return 0;
					break;
				default:
					printf("wrong input");
					break;
				}

			} 
		
		} while (inputi != 'q');
}

char get_yes_or_no()
{
	int flag = 0;
	char input = 0;

	do
	{
		scanf(" %c", &input);

		if ((input == 'Y') || (input == 'N')  || (input == 'y') || (input == 'n'))
		{

			flag = 1;
		}
		else
		{
			printf("Wrong input, try again\n");
			flag = 0;
		}



	} while (flag == 0);
	
	return (input);

}
