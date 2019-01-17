#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int isalphabet(char *number, int lenght);
void get_row_column(int *row, int *column);
void allocate_memory(int ***matrix, int row, int column);
void get_elements(int***matrix, int row, int column);
void identity_matrix(int **matrix, int row, int column);
void print_matrix(int **matrix, int row, int column);
int get_valid_integer(int minimum, int maximum);
int isfloat(char *number, int lenght);

int main()
{
	int row, column = 0;
	int **matrix = 0;

	get_row_column(&row, &column);
	allocate_memory(&matrix, row, column);
	get_elements(&matrix, row, column);
	identity_matrix(matrix, row, column);

	getch();
	return 0;
}
void get_row_column(int *row, int *column)
{
	do
	{ 
		printf("Input number of Rows for the matrix : ");
		(*row) = get_valid_integer(1, 100);
		printf("Input number of Columns for the matrix : ");
		(*column) = get_valid_integer(1, 100);

		if (*row != *column) printf("A square matrix has same number of rows and columns, try again\n");
		

	} while (*row != *column);
}
void allocate_memory(int ***matrix, int row, int column)
{
	int i = 0;
	*matrix = (int**)calloc(row, sizeof(int*));
	if (*matrix == NULL)
	{
		fputs("Error allocating memory", stderr);
		exit(0);
	}
	for (i = 0; i < column; i++)
	{
		(*matrix)[i] = (int*)calloc(column, sizeof(int));
		if ((*matrix)[i] == NULL)
		{
			fputs("Error allocating memory", stderr);
			exit(0);
		}
	}
}
void get_elements(int***matrix, int row,int column)
{
	int i, j = 0;
	printf("\nInput elements in the first matrix : ");
	printf("\n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			printf("element - [%d][%d] : ",i, j);
			((*matrix)[i][j]) = get_valid_integer(0, 1);
		}
	}
}
void identity_matrix(int **matrix, int row, int column)
{
	int i, j = 0;
	int count = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (i == j && matrix[i][j] == 1)
			{
				count++;
			}
		}
	}
	print_matrix(matrix, row, column);

	if (count == row) printf("\nThe matrix is an identity matrix");
	else printf("\nThe matrix is not an identity matrix");

}
void print_matrix(int **matrix, int row, int column)
{
	int i, j = 0;
	printf("\nThe matrix is : ");
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
int get_valid_integer(int minimum, int maximum)
{
	char buffer[20];
	int success = 0;
	int lenght = 0;
	int number = 0;
	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		lenght = strlen(buffer);
		buffer[lenght-1] = '\0';
		lenght = lenght - 1;

		if (isfloat(buffer, lenght))
		{
			printf("Floats not allowed\n");
		}
		else if (isalphabet(buffer, lenght))
		{
			printf("Alphabets or special characters not allowed");
		}
		else
		{
			sscanf(buffer, "%d", &number);
			if (number<minimum || number >maximum)
			{
				printf("Out of range\n");
			}
			else
			{
				success = 1;
				return number;
			}
		}
	} while (success == 0);
}
int isfloat(char *number, int lenght)
{
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if (number[i] == '.')
		{
			return 1;
		}
	}
	return 0;
}
int isalphabet(char *number, int lenght)
{
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		if (!isdigit(number[i])) return 1;	
	}
	return 0;
}