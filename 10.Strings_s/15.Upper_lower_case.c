#pragma warning(disable:4996)
#include <stdio.h>

void print_buffer(char *n);
void convert(char *k);
int isupper(int n);
int islower(int n);
void convert1(int *n, int s);
int stringlenght(char *n);

int main()
{
	char buffer[50];
	printf("Input the string : ");
	fgets(buffer, sizeof(buffer), stdin);
	convert(buffer);
	print_buffer(buffer);

	getch();
	return 0;
}
void convert(char *n)
{
	int s = 0;
	char temp[50];
	int lenght = stringlenght(n);
	int i = 0;
	for (i = 0;i < lenght;i++)
	{
		if (isupper(n[i])) convert1(&n[i], 0);	
		else if (islower(n[i]))convert1(&n[i], 1);
		else{}
	}
}
void copy(char *source, char *destination,int lenght)
{
	int i = 0;
	char *k = &destination[0];
	for (i = 0;i < lenght;i++)
	{
		k[i] = source[i];
	}
	k[lenght] = '\0';
}

int isupper(int n)
{
	if (n > 64 && n < 91)
	{
		return 1;
	}
	return 0;
}
int islower(int n)
{
	if (n > 96 && n < 123)
	{
		return 1;
	}
	return 0;
}
void convert1(int *n,int s)
{
	if (s == 0) *n = *n + 32;
	else *n = *n - 32;
}
int stringlenght(char *n)
{
	int i = 0;
	while (n[i] != '\n')
	{
		i++;
	}
	return i;
}
void print_buffer(char *n)
{
	printf("%s", n);
}