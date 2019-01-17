#pragma warning(disable:4996)

#include <stdlib.h>
#include <stdio.h>

struct perfectrange get_ranges();
int getperfectnumbers(struct perfectrange m, int *perfectnumbers);
void print_perfect_ranges(int perfect, int *numbers);

typedef struct perfectrange
{
	int start;
	int end;

}numbers;

int main()
{
	numbers m;
	int *k;
	int perfectnumbers = 0;
	
	m = get_ranges();
	k = getperfectnumbers(m, &perfectnumbers);
	print_perfect_ranges(perfectnumbers, k);

	free(k);
	getch();
	return 0;
}

struct perfectrange get_ranges()
{
	numbers m;
	do
	{
		printf("Input the starting range or number : ");
		scanf("%d", &m.start);

		printf("Input the ending range of number : ");
		scanf("%d", &m.end);

		if (m.start > m.end)
		{
			printf("\nThe starting range must be smaller than ending\n");
		}

	} while (m.start > m.end);

	return m;
}
int getperfectnumbers(struct perfectrange m, int *perfectnumbers)
{
	int n = m.end - m.start;
	int perfect = 0;
	int j = 0;
	int sum = 0;
	int i = 0;
	int *numbers = (int*)calloc(n, sizeof(int));

	if (numbers == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}

	for (i = m.start+1; i <=m.end; i++)
	{
		for (j = 1; j <=i; j++)
		{
			if (i%j==0)
			{
				sum += j;
			}
		}
		if (sum == i+i)
		{
			numbers[perfect] = i;
			perfect++;
		}
		sum = 0;
	}
	*perfectnumbers = perfect;
	return numbers;
}
void print_perfect_ranges(int perfect,int *numbers)
{
	int i = 0;

	printf("\nThe Perfect numbers within the given range: ");

	for (i = 0; i < perfect; i++)
	{
		printf("%d ", numbers[i]);
	}
}

