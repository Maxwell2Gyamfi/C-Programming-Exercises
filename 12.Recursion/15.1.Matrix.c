#pragma warning (disable:4996)
#include <stdio.h>

#define ARRAY_SIZE 50

int m(int a[][ARRAY_SIZE], int b[][ARRAY_SIZE], int c[][ARRAY_SIZE], int row, int column);
void print(int c[][ARRAY_SIZE], int rows, int columns);
int get_elements(int arr1[][ARRAY_SIZE], int arr2[][ARRAY_SIZE], int *rows1, int *columns1);

int main()
{
	int s = 0;
	int rows1 = 0; int columns1 = 0;
	int a[ARRAY_SIZE][ARRAY_SIZE];
	int b[ARRAY_SIZE][ARRAY_SIZE];
	int c[ARRAY_SIZE][ARRAY_SIZE];
	get_elements(a, b, &rows1, &columns1) ? m(a, b, c, rows1, columns1),
		print(c, rows1, columns1) : printf("Matrix multiplication is not possible");
	
	getch();
	return 0;
}
int m(int a[][ARRAY_SIZE], int b[][ARRAY_SIZE],int c[][ARRAY_SIZE],int row,int column)
{
	static int i = 0;
	static int j = 0;
	static int k = 0;
	static int l = 0;
	static int r = 0;
	int sum = 0;
	if (i >= row)
	{
 		return 1;
	}
	
	if (j < row)
	{
		if (k < column)
		{
			sum += a[j][l] * b[l][k];
			c[j][k] = sum;
			k++;
			sum = 0;
			m(a, b, c, row, column);
			
		}
		j++;
		k = 0;
		i++;
		sum = 0;
		m(a, b, c, row, column);
	}

}
int get_elements(int arr1[][ARRAY_SIZE], int arr2[][ARRAY_SIZE], int *rows1, int *columns1)
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
	
	if (row == columns)
	{

		printf("Input the elements in first array: ");
		printf("\n");
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < column; j++)
			{
				printf("Element [%d],[%d] : ", i, j);
				scanf("%d", &(arr1[i][j]));
			}
		}
		printf("Input the elements in second array: ");
		printf("\n");
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns; j++)
			{
				printf("Element [%d],[%d] : ", i, j);
				scanf("%d", &(arr2[i][j]));
			}
		}
		*rows1 = row;
		*columns1 = columns;
	}
	else
	{
		return 0;
	}
	return 1;
}
void print(int c[][ARRAY_SIZE],int rows,int columns)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < columns; j++)
		{
			printf("%d ", c[i][j]);
		}
		printf("\n");
	}
}
