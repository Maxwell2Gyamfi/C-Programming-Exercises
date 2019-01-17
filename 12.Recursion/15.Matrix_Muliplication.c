#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void get_elements(int **arr, int **arr2, int *rows1, int *columns1);
int get_sum(int **a, int **b, int row, int column, int c[][20], int j);
void print_array(int c[20][20], int row, int column);

int main()
{
	int i = 0;
	int row = 0; 
	int column = 0; 
	int **first;
	int third[20][20];
	int **arr2;

	first = (int**)calloc(20, sizeof(int*));
	for (i = 0; i < 20; i++)
	{
		first[i]= (int*)calloc(20, sizeof(int));
	}
	arr2 = (int**)calloc(20, sizeof(int*));
	for (i = 0; i < 20; i++)
	{
		arr2[i] = (int*)calloc(20, sizeof(int));
	}
	
	get_elements(first, arr2, &row, &column);
	get_sum(first, arr2, row, column, third, 0);

	getch();
	return 0;
}
void get_elements(int **arr,int **arr2,int *rows1,int *columns1)
{
	int j = 0;
	int i = 0;
	int row = 0;
	int column = 0;
	int rows = 0;
	int columns = 0;

	printf("Input the number of rows in the first matrix: ");
	scanf("%d", &row);
	printf("Input the number of columns int the first matrix : ");
	scanf("%d", &column);

	printf("Input the number of rows in the second matrix: ");
	scanf("%d", &rows);
	printf("Input the number of columns int the second matrix : ");
	scanf("%d", &columns);

	
	printf("Input the elements in first array: ");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Element [%d],[%d] : ", i, j);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("Input the elements in second array: ");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("Element [%d],[%d] : ", i, j);
			scanf("%d", &arr2[i][j]);
		}
	}
	printf("%d", arr2[i][j]);
	*rows1 = row;
	*columns1 = column;
}

int i = 0;
int sum = 0;
int s = 0;
int k = 0;

int get_sum(int **a, int **b, int row, int column,int c[][20],int j)
{
	if (i == row)
	{
		print_array(c, row, column);
		return 1;
	}
	else
	{
		if (j < column)
		{
			sum = sum + (a[i][j] * b[i][j]);
		}
		
		get_sum(a, b, row, column, c, j + 1);
	}
}
void print_array(int c[20][20], int row, int column)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("Element [%d],[%d] is %d", i, j, c[i][j]);
		}
	}
}