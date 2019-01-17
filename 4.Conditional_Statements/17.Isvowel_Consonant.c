#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char character();
void decide_vowel_consonant(char *character);

int main()
{
	character();

	getch();
	return 0;
}
char character()
{
	char buffer[4];
	char character[4];

	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", &character);

	decide_vowel_consonant(character);

}
void decide_vowel_consonant(char *character)
{
	size_t i;
	size_t j;

	
	char vowels[6] = { 'a','e','i','o','u' };
	
	for (i = 0; i < strlen(character); i++)
	{
		if (isalpha(character[i]))
		{
			character[i] = tolower(character[i]);

			for (j = 0; j < sizeof(vowels)/sizeof(char); j++)
			{
				if (character[i] == vowels[j])
				{
					printf("The alphabet is a vowel\n");
					return 0;
				}
			}
			printf("The alphabet is a consonant\n");
		}
		else
		{
			printf("Error, you didnt enter an aplphabet\n");
		}
	}


}