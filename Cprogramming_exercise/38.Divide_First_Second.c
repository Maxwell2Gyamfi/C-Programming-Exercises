#pragma warning (disable:4996)

#include<stdio.h>
#include <string.h>
struct allnumbers decison_make(int *numbers, int size);
void final_decision(struct allnumbers p);
int *get_numbers(int *size);



struct allnumbers 
{
	int yes;
	char response_result[25];

};

int main()
{
	struct allnumbers q;
	int size = 0;
	int *the_numbers = 0;

	the_numbers = get_numbers(&size);
	q = decison_make(the_numbers, size);
	final_decision(q);
	getch();

	return 0;
}
int *get_numbers(int *size)
{
	char alphabets[3][8] = { "first","second" };

	static int numbers[2];

	int lenght = sizeof(numbers) / sizeof(int);

	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("Enter the %s number: ", alphabets[i]);
		scanf("%d", &numbers[i]);
	}
	*size = lenght;
	return numbers;
}
struct allnumbers decison_make(int *numbers, int size)
{
	float result = 0;
	struct allnumbers p;
	int i = 0;
	int j = 0;

	for (i = 0; i < size-1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if(numbers[j]>0)
			{ 
				result = numbers[i] / numbers[j];
				sprintf(p.response_result, "%1.1f", result);
				p.yes = 1;
				return p;

			}
			else
			{
				strcpy(p.response_result, "Division not possible");
				return p;
			}
		}
	}
}
void final_decision(struct allnumbers p)
{
	if (p.yes == 1)
	{
		printf("%s", p.response_result);
	}
	else
	{
		printf("%s", p.response_result);
	}
}