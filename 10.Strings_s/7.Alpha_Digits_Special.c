#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void get_string(char *n);
void copy(char *destination, char *source);
int lenghtstring(char *n);
int conditions(int *alpha, int*num, int *special, char *n);
int isalphabet(char n);
int isnumber(char n);
void count(int alpha, int num, int special);


int main()
{
	int alpha, num, special = 0;
	char n[50];
	get_string(n);
	conditions(&alpha, &num, &special, n);
	count(alpha, num, special);


	getch();
	return 0;
}
void get_string(char *n)
{
	char buffer[50];
	printf("Enter a string: ");
	fgets(buffer, sizeof(buffer), stdin);
	copy(n, buffer);
}
void copy(char *destination, char *source)
{
	int i = 0;
	char *s = NULL;
	s = &destination[0];

	int lenght = lenghtstring(source);

	for (i = 0;i <= lenght;i++)
	{
		s[i] = source[i];
	}
}
int lenghtstring(char *n)
{
	int i = 0;
	while (n[i] != '\n')
	{
		i++;
	}
	return i;
}
int conditions(int *alpha, int*num, int *special,char *n)
{
	int alphab =0; int nume = 0;int speciale = 0;
	int lenght = lenghtstring(n);
	int i = 0;
	for (i = 0;i <lenght;i++)
	{
		if (isalphabet(n[i])) alphab++;
		else if (isnumber(n[i]))nume++;
		else speciale++;
	}
	*alpha = alphab;
	*num = nume;
	*special = speciale;
}
int isalphabet(char n)
{
	int i = 0;
	if (n > 64 && n<91)
	{
		return 1;
	}
	else if (n > 96 && n < 123)
	{
		return 1;
	}
	else return 0;
}
int isnumber(char n)
{
	if (n > 47 && n<58)
	{
		return 1;
	}
	return 0;
}
void count(int alpha, int num, int special)
{
	printf("\nNumber of Alphabets in the string is :%d ", alpha);
	printf("\nNumber of Digits in the string is : %d",num);
	printf("\nNumber of Special characters in the string is : %d", special);

}