#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



struct numbers getpait_of_numbers(int *size2);
struct numbers get_bigger_smaller(struct numbers p);
struct numbers *get_loop_numbers(struct numbers p);

void get_sum(struct numbers p, struct numbers *q);


int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);


typedef struct numbers
{
	int pair_of_numbers[3];
	int *loop_numbers;
	int bigger;
	int smaller;
	int malloc_size;
	int sum_size;

}divisible;

int main()
{
	int size = 0;
	divisible p;
	divisible *q;
	divisible m;

	p = getpait_of_numbers(&size);
	m = get_bigger_smaller(p);
	q = get_loop_numbers(m);
	get_sum(m, q);

	getch();
	return 0;
}

struct numbers getpait_of_numbers(int *size2)
{
	divisible p;
	int i = 0;
	int size = 2;

	*size2 = size;
	printf("Enter the pair of numbers: ");
	for (i = 0; i < size; i++)
	{
		p.pair_of_numbers[i] = getvalidnumber(1, 2000);
	}
	return p;
}
struct numbers get_bigger_smaller(struct numbers p)
{
	divisible q;
	int i = 0;

	if (p.pair_of_numbers[0] < p.pair_of_numbers[1])
	{
		q.smaller = p.pair_of_numbers[0];
		q.bigger = p.pair_of_numbers[1];

	}
	else
	{
		q.smaller = p.pair_of_numbers[1];
		q.bigger = p.pair_of_numbers[0];
	}
	q.malloc_size = q.bigger - q.smaller;
	q.sum_size = q.bigger;


	return q;
}
struct numbers *get_loop_numbers(struct numbers p)
{
	divisible *q = 0;
	int i = 0;
	int size = 0;
	size =p.malloc_size;

	q = (struct numbers*)malloc(size*sizeof(struct numbers));

	q->loop_numbers= (struct numbers*)malloc(size*sizeof(struct numbers));

	if (q->loop_numbers == 0)
	{
		printf("Error allocating");
		exit(1);
	}
	for (i = p.smaller; i <= p.bigger; i++)
	{
		if (i % 17 != 0)
		{
			q->loop_numbers[i] = i;
		}
		else
		{
			q->loop_numbers[i] = 0;
		}
	}
	return q;
}
void get_sum(struct numbers p, struct numbers *q)
{
	int i = 0;
	int sum = 0;

	for (i = 0; i <= p.sum_size; i++)
	{
		if(q->loop_numbers[i]<=0){}
		else
		{
			sum += q->loop_numbers[i];
		}
	}
	printf("%d", sum);
}
int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;
	do {

		scanf("%s", numbers);

		if (hasdot(numbers))
		{
			printf("Floats not allowed");
		}
		else if (is_special_character(numbers))
		{
			printf("Special characters not allowed");
		}
		else if (isalphabet(numbers))
		{
			printf("Alphabets not allowed");
		}
		else
		{
			number = atoi(numbers);
			if ((number < minimum) || number > maximum)
			{
				printf("Out of range");
			}
			else
			{
				success = 1;
				return number;
			}
		}

	} while (success == 0);

}
int hasdot(char *number)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j < strlen(number); j++)
		{
			if (number[j] == '.')
			{
				return 1;
			}
		}
		return 0;
	}
}
char is_special_character(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number);

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j <lenght; j++)
		{
			if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
			{

			}
			else
			{
				return 1;
			}

		}
		return 0;
	}
}
char isalphabet(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number) - 1;

	for (i = 0; i < 1; i++)
	{
		for (j = 0; j <= lenght; j++)
		{
			if (isalpha(number[j]))
			{
				return 1;
			}
		}
	}
	return 0;

}
