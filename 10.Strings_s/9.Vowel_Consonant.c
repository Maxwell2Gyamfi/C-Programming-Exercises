#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

void vowel_consonants(char *n);
int isvowel(char n);
void printf_stuff(int vowels, int consonants);
int isalpha(char n);

int main()
{
	char string[50];
	printf("Input the string : ");
	fgets(string, sizeof(string), stdin);
	vowel_consonants(string);

	getch();
	return 0;
}
void vowel_consonants(char *n)
{
	int vowels = 0;
	int consonants = 0;
	int alphabets = 0;
	int i = 0;
	int lenght = strlen(n);
	for (i = 0;i < lenght;i++)
	{
		if(isalpha(n[i]))
		{
			if (isvowel(n[i]))
			{
				vowels++;
			}
			else
			{
				consonants++;
			}
		}
	}
	printf_stuff(vowels, consonants);
}
int isvowel(char n)
{
	int i = 0;
	char vowels[5] = { 'a','e','i','o','u' };
	for (i = 0;i < 5;i++)
	{
		if (n == vowels[i])return 1;
	}
	return 0;

}
void printf_stuff(int vowels, int consonants)
{
	printf("The total number of vowel in the string is : %d", vowels);
	printf("\nThe total number of consonants in the string is: %d", consonants);
}
int isalpha(char n)
{
	int i=n;
	if (i > 64 && i < 91 || i>96 && i < 123)
	{
		return 1;
	}
	return 0;

}