#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#define SIZE 50
void bubble_sort(char strings[][SIZE], int elements);
int get_strings(char strings[][SIZE]);
void print_new_array(char n[][50], int lenght);
void bigger_character(char strings[][SIZE], int lenght, int start);
void print_new_array(char n[][50], int lenght);
int main()
{
	
	char strings[50][SIZE];
	int elements = get_strings(strings);

	bubble_sort(strings, elements);
	print_new_array(strings, elements);

	getch();
	return 0;
}
int get_strings(char strings[][SIZE])
{
	int s = 0;
	int i = 0;
	int j = 0;
	printf("Input number of strings : ");
	scanf("%d", &s);

	printf("Input 3 strings: ");
	printf("\n");
	for (i = 0;i < s;i++)
	{
			scanf("%s", strings[i]);	
	}
	return s;
}
void bubble_sort(char strings[][SIZE],int elements)
{
	char first, second = 0;
	int lenght = 0;
	int lenght2 = 0;
	
	char temp[20];
	int i, j,p,m=0;
	int start = 0;
	for (i = 0;i < elements - 1;i++)
	{
		for (j = i + 1;j < elements;j++)
		{
			lenght = strlen(strings[i]);
			lenght2 = strlen(strings[j]);
			if (lenght > lenght2)
			{
				strcpy(temp, strings[i]);
				strcpy(strings[i], strings[j]);
				strcpy(strings[j], temp);
			}
			start = i;
			if(lenght==lenght2) bigger_character(strings, lenght,start);
			}
		}
}

void bigger_character(char strings[][SIZE], int lenght, int start)
{
	int starting = 0;
	int x = 0;
	char temp[50];
	int m, n = 0;

		while (x < lenght)
		{
			char first = strings[start][starting];
			char second = strings[start + 1][starting];

			if (first < second)
			{
				break;
			}
			if (first>second)
			{
				strcpy(temp, strings[start]);
				strcpy(strings[start], strings[start + 1]);
				strcpy(strings[start + 1], temp);
				break;
			}
			starting++;
			x++;
		}
}

void print_new_array(char n[][50], int lenght)
{
	int i = 0;
	printf("\nThe strings appears after sorting : ");
	printf("\n");
	for (i = 0;i < lenght;i++)
	{
		printf("%s\n", n[i]);
	}
}


