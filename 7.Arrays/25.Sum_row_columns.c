#pragma warning(disable:4996)

#include <stdio.h>

int get_size();
void get_elements(int matrix[][20], int size);
void print_matrix(int matrix[][20], int size, int sum[]);
void get_sum(int matrix[][20], int size);
void merge(int *result1, int l, int *result2, int k);

int main()
{
	int matrix[20][20];
	int size = 0;
	size = get_size();
	get_elements(matrix, size);
	get_sum(matrix, size);

	getch();
	return 0;
}
int get_size()
{
	int size = 0;
	printf("Enter the size of square matrix : ");
	scanf("%d", &size);

	return size;
}
void get_elements(int matrix[][20], int size)
{
	int i, j = 0;

	printf("Input elements in the first matrix : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("element - [%d],[%d] : ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
}
void print_matrix(int matrix[][20], int size, int sum[])
{

	int i, j = 0;
	int l = 0;
	int s = 0;
	int q = 0;

	printf("\nThe sum or rows and columns of the matrix is : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);

			if (j == size - 1)
			{
				printf("|");
				
				printf("%d", sum[l++]);
			}
		}
		printf("\n");

		if (i == size - 1)
		{
			for (q = 0; q < size; q++)
			{
				printf("--");
			}
			printf("\n");
			for (s = 0; s < size; s++)
			{
				printf("%d ", sum[l++]);
			}	
		}
	}
}
void get_sum(int matrix[][20], int size)
{
	
	int i, j, k;
	int l = 0;int m = 0;
	int sum = 0;
	
	int resultrow[20];
	int result_column[20];

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			sum += matrix[i][j];
		}
	
		resultrow[l++] = sum;
		sum = 0;

		for (k = 0; k < size; k++)
		{
			sum += matrix[k][i];
		}
		result_column[m++] = sum;
		sum = 0;
	}
	merge(resultrow, l, result_column, m);
	print_matrix(matrix, size, resultrow);

}
void merge(int *result1, int l, int *result2, int k)
{
	int i = 0;

	int *s = &result1[0];
	for (i = 0; i < k; i++)
	{
		s[l] = result2[i];
		l++;
	}
}

