#pragma warning (disable:4996)
#include <stdio.h>
#include <stdlib.h>

struct Ranges get_numbers1();
int get_numbers(struct Ranges *m, int *size);
void print_numbers(struct Ranges m, int size);

typedef struct Ranges
{
	int start;
	int end;
	int number;
	int *numbers;
	int sum;

}ranges;


int main()
{
	int size = 0;
	ranges m;


	m = get_numbers1();
	get_numbers(&m, &size);
	print_numbers(m, size);

	getch();
	return 0;
}
struct Ranges get_numbers1()
{
	ranges m;

	printf("Enter the number: ");
	scanf("%d", &m.number);

	printf("Enter the starting range: ");
	m.start = range(0);

	printf("Enter the ending range: ");
	m.end = range(m.start);

	return m;

}

int get_numbers(struct Ranges *m,int *size)
{
	
	int l = 0;
	int i = 0;
	int sum = 0;

	*size = (m->end - m->start) / m->number;
	m->numbers = (struct Ranges*)calloc(*size, sizeof(struct Ranges));
    
	for (i = m->start; i < m->end; i++)
	{
		if (i%m->number == 0)
		{
			m->numbers[l] = i;
			sum += i;
			l++;
		}
	}
	m->sum = sum;
}
void print_numbers(struct Ranges m,int size)
{
	int i = 0;

	printf("Numbers between %d and %d divisible by %d :", m.start, m.end, m.number);

	for (i = 0; i < size; i++)
	{
		printf("%d ", m.numbers[i]);
	}
	printf("\nThe sum : %d", m.sum);
}

int range(int m)
{
	int success = 0;
	int number = 0;

	do
	{
		scanf("%d", &number);

		if (number < m)
		{
			printf("Ending range must be bigger than starting range\n");
		}
		else
		{
			success = 1;
			return number;
		}

	} while (success == 0);
}