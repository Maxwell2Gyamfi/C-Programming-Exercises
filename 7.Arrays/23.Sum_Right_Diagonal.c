#pragma warning(disable:4996)

#include <stdio.h>
#define Y 10

void get_sum(int matrix[][Y],int size);
void get_row_column(int *size);
void get_elements(int matrix[][Y], int size);
void print_matrix(int matrix[][Y], int size, int sum);

int main()
{
	int size = 0;
	int matrix[10][Y];
	int sum[10][Y];
	get_row_column(&size);
	get_elements(matrix, size);
	get_sum(matrix,size);

	getch();
	return 0;
}
void get_row_column(int *size)
{
	printf("Input the size of the square matrix :  ");
	scanf("%d", &(*size));
}
void get_elements(int matrix[][Y], int size)
{
	int i = 0; int j = 0;
	printf("\nInput elements in the first matrix : ");
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
void get_sum(int matrix[][Y],int size)
{
	int sum = 0;
	int i, j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i == j)
			{
				sum += matrix[i][j];
			}
		}
	}
	print_matrix(matrix, size, sum);
}
void print_matrix(int matrix[][Y], int size,int sum)
{
	int i, j = 0;

	printf("\nThe matrix is : ");
	printf("\n");
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\nAddition of the right Diagonal elements is : %d", sum);

}
