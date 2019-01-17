#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>


void print_sum(int **matrix, int size, int sum);
int get_square_size();
int **get_matrix_size(int size);
void get_elements(int size, int **matrix);
void get_sum(int size, int **matrix);
void free_matrix(int **matrix, int size);

int main()
{
	int size = 0;
	int **matrix = 0;

	size = get_square_size();
	matrix = get_matrix_size(size);
	get_elements(size, matrix);
	get_sum(size, matrix);
	free_matrix(matrix, size);
	free(matrix);

	getch();
	return 0;
}
int get_square_size()
{
	int size = 0;
	printf("Input the size of the square matrix : ");
	scanf("%d", &size);
	return size;
}
int **get_matrix_size(int size)
{
	int i = 0;

	int **matrix = (int **)calloc(size, sizeof(int*));
	for (i = 0; i < size; i++)
	{
		matrix[i]= (int*)calloc(size, sizeof(int));
	}
	return matrix;
}
void get_elements(int size, int **matrix)
{
	int i, j = 0;

	printf("Input elements in the first matrix : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("element - [%d],[%d] : ",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
}
void get_sum(int size, int **matrix)
{
	int i, j = 0;
	int sum = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (i != j)
			{
				sum += matrix[i][j];
			}
		}
	}
	print_sum(matrix, size, sum);
}
void print_sum(int **matrix, int size, int sum)
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
	printf("\nAddition of the left Diagonal elements is : %d", sum);

}
void free_matrix(int **matrix, int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
	{
		free(matrix[i]);
	}

}
