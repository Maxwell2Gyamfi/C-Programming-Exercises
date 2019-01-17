#pragma warning (disable:4996)
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int get_biggest(int *numbers);
void decision(int position, int *numbers);
int *get_numbers();
int make_decison(int *numbers);
char remove_white_space(char *numbers);

int main()
{

	int *numbers;
	int biggest_position = 0;
	numbers = get_numbers();
	biggest_position = get_biggest(numbers);
	//make_decison(numbers);
	decision(biggest_position,numbers);

	getch();
	return 0;
}
int *get_numbers()
{
	int i = 0;
	static int numbers[3];

	fputs("Enter 3 numbers: ", stdout);
	
	for (i = 0; i < 3; i++)
	{
		scanf("%d", &numbers[i]);
	}

	return numbers;
}
int make_decison(int *numbers)
{
	int i = 0;
	int j = 0;
	int l = 0;

	for (i = 0; i < 3 - 2; i++)
	{
		for (j = i+1; j < 3 - 1; j++)
		{
			for (l = i + 2; l < 3; l++)
			{
				if (numbers[i] > numbers[j] && numbers[l])
				{
					fputs("The 1st number is the greatest among three",stdout);
				}
				else if (numbers[j] > numbers[i] && numbers[l])
				{
					fputs("The 2nd number is the greatest among three", stdout);
				}
				else
				{
					fputs("The 3rd number is the greatest among three", stdout);
				}
			}
		}
	}

}
char remove_white_space(char *numbers)
{
	int i = 0;

	for (i = 0; i < strlen(numbers); i++)
	{
		if (numbers[i] == '\n')
		{
			*(numbers + i) = '\0';
		}

	}
}
int get_biggest(int *numbers)
{
	int i = 0;
	int position = 0;
	int biggest = 0;

	biggest = numbers[0];

	for (i = 0; i < 3; i++)
	{
		if (numbers[i] >= biggest)
		{
			biggest = numbers[i];
			position = i + 1;
		}
	}
	return position;
}
void decision(int position, int *numbers)
{
	int i = 0;
	
	for (i = 0; i < 1; i++)
	{
		printf("1st Number = %d  2nd Number = %d  3rd Number = %d\n", numbers[i], numbers[i + 1], numbers[i + 2]);
	}
	if (position == 1)
	{
		fputs("The 1st number is the greatest among three", stdout);
	}
	else if (position == 2)
	{
		fputs("The 2nd number is the greatest among three", stdout);
	}
	else
	{
		fputs("The 3rd number is the greatest among three", stdout);
	}


}
