#pragma warning(disable:4996)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int size_of_matrix();
void get_elements(int ***matrix, int size);
void print_elements(int matrix[][20], int size, int **matrix1);
int **get_lower_triangular_matrix(int **matrix, int size);
void copy_array(int **matrix, int matrix1[][20], int size);

int main()
{
	int size = 0;
	int **matrix = 0;
	int **lower_triangular;

	size = size_of_matrix();
	get_elements(&matrix, size);

	lower_triangular = get_lower_triangular_matrix(matrix, size);
	print_elements(lower_triangular, size,matrix);

	getch();
	return 0;
}
int size_of_matrix()
{
	int size = 0;

	printf("Input the size of the square matrix : ");
	scanf("%d", &size);
	return size;
}
void get_elements(int ***matrix, int size)
{
	int i = 0;
	int j = 0;

	*matrix = (int**)calloc(size, sizeof(int*));

	for (i = 0; i < size; i++)
	{
		(*matrix)[i]= (int*)calloc(size, sizeof(int));
	}

	printf("Input elements in the first matrix :  : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("element - [%d],[%d] : ",i,j);
			scanf("%d", &((*matrix)[i][j]));
		}
	}
}
int **get_lower_triangular_matrix(int **matrix, int size)
{
	int lower_triangular[20][20];

	copy_array(matrix, lower_triangular, size);

	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			lower_triangular[i][j] = 0;
		}
	}
	return lower_triangular;

}
void copy_array(int **matrix, int matrix1[][20], int size)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			matrix1[i][j] = matrix[i][j];
		}
	}
}
void print_elements(int matrix[][20], int size,int **matrix1)
{
	int i, j = 0;
	

	printf("\nThe matrix is : ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix1[i][j]);
		}
		printf("\n");
	}

	printf("\nSetting zero in lower triangular matrix ");
	printf("\n");

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}