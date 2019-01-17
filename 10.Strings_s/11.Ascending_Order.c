#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
void get_string(char *n);
void sort_order(char *n);
void print_new_string(char *n);
int main()
{
	char n[50];
	get_string(n);
	sort_order(n);
	print_new_string(n);
	getch();

	return 0;
}
void get_string(char *n)
{
	char buffer[50];
	printf("Input a string: ");
	fgets(buffer, sizeof(buffer), stdin);
	strcpy(n, buffer);
}
void sort_order(char *n)
{
	int s, x,i,j,temp = 0;
	char *k = &n[0];
	int lenght = strlen(n);

	for (i = 0;i < lenght-1;i++)
	{
		for (j = i + 1;j < lenght;j++)
		{
			s = n[i];
			x = n[j];
			if (s > x)
			{
				temp = k[i];
				k[i] = k[j];
				k[j] = temp;
			}
		}
	}
}
void print_new_string(char *n)
{
	printf("After sorting the string appears like : %s", n);
}