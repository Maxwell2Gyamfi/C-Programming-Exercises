#pragma warning(disable:4996)
#include <stdio.h>

void get_matrix_size(int *rows, int *column);
int **get_matrices_size(int row, int column, int situation);
void get_matrix_multiplication(int **matrix1, int **matrix2, int **result, int row, int column);
void print_matrix(int **matrix, int row, int column, int situation);
void free_array(int **matrix, int size);

int main()
{
	int column, rows = 0;
	int **matrix1, **matrix2, **result = 0;

	get_matrix_size(&rows, &column);
	matrix1 = get_matrices_size(rows, column, 1);
	matrix2 = get_matrices_size(rows, column, 2);
	result = get_matrices_size(rows, column, 0);
	get_matrix_multiplication(matrix1, matrix2, result, rows, column);
	print_matrix(matrix1, rows, column, 1);
	print_matrix(matrix2, rows, column, 2);
	print_matrix(result, rows, column, 0);

	free_array(matrix1, rows);
	free_array(matrix2, rows);
	free_array(result, rows);
	free(matrix1);
	free(matrix2);
	free(result);

	getch();
	return 0;
}
void get_matrix_size(int *rows,int *column)
{
	printf("Input the rows and columns of first matrix: ");
	scanf("%d%d", &(*rows), &(*column));
}
int **get_matrices_size(int row, int column,int situation)
{
	int i = 0;
	int j = 0;
	int **matrix = (int**)calloc(row, sizeof(int*));
	for (i = 0; i < column; i++)
	{
		matrix[i] = (int*)calloc(column, sizeof(int));
	}

	if (situation == 1 || situation == 2)
	{
		if (situation == 1)printf("\nInput elements in the first matrix : ");
		else ("\nInput elements in the first matrix : ");
		printf("\n");

		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				printf("element - [%d],[%d] : ", i, j);
				scanf("%d", &matrix[i][j]);
			}
		}
	}

	return matrix;
}
void get_matrix_multiplication(int **matrix1, int **matrix2,int **result, int row, int column)
{
	int sum = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			for (k = 0; k < column; k++)
			{
				sum += matrix1[i][k] * matrix2[k][j];
			}
			result[i][j] = sum;
			sum = 0;
		}
	
	}
}
void print_matrix(int **matrix, int row, int column, int situation)
{
	int i, j = 0;

	if (situation == 1)printf("\nThe First matrix is : ");
	else if (situation == 2)printf("\nThe Second matrix is : ");
	else printf("\nThe Multiplication of two matrix is : ");
	printf("\n");

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}
void free_array(int **matrix, int size)
{

	int i = 0;
	for (i = 0; i < size; i++)
	{
		free(matrix[i]);
	}
}
