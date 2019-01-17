#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void get_string(char *name, int *lenght);
void get_vowel_consonant(char *name, int lenght, int *vowels, int *consonants);
int main()
{
	int vowels = 0;
	int consonants = 0;
	int lenght = 0;
	char string[20];

	get_string(string, &lenght);
	get_vowel_consonant(string, lenght, &vowels, &consonants);

	printf("\nNumber of vowels: %d", vowels);
	printf("\nNumber of constant : %d", consonants);
	getch();
	return 0;
}
void get_string(char *name,int *lenght)
{
	char string[20];

	printf("Input a string : ");
	scanf("%s", string);
	strcpy(name, string);
	*lenght = strlen(string);

}
void get_vowel_consonant(char *name, int lenght,int *vowels,int *consonants)
{
	int vows = 0;
	int cons = 0;
	int i = 0;
	for (i = 0; i < lenght; i++)
	{
		*name = tolower(*name);
		switch (*name)
		{
		case'a':vows++;break;
		case'e':vows++;break;
		case'i':vows++;break;
		case'o':vows++;break;
		case'u':vows++;break;
		default:cons++;break;
		}
		name++;
	}
	*vowels = vows;
	*consonants = cons;
}
