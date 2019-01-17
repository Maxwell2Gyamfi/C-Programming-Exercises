#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGHT_NAME 16
#define MIN_LENGHT_NAME 2

int get_valid_name(char *name);
int has_special_character_name(char *name);
char remove_new_line(char *name);


int get_valid_name(char *name1)
{
	int success = 0;
	char name[MAX_LENGHT_NAME + 1];

	char ch;

	while ((ch = getchar()) != '\n' && ch != EOF);



	do
	{
		fgets(name, sizeof(name), stdin);
		remove_new_line(name);

		int lenght = strlen(name);

		if (has_special_character_name(name))
		{
			fputs("Error special characters not allowed\n", stderr);
		}

		else
		{
			if (lenght < MIN_LENGHT_NAME)
			{
				fputs("Too few characters,your name should be longer\n", stderr);
			}
			else if (lenght > MAX_LENGHT_NAME)
			{
				fputs("Too many characters,your name should be shorter\n", stderr);
			}
			else
			{
				strcpy(name1, name);
				success = 1;
				return success;
			}
		}
	} while (success == 0);

}
int has_special_character_name(char *name)
{
	int i = 0;
	int lenght = strlen(name);

	for (i = 0; i < lenght; i++)
	{
		if (isalpha(name[i]) || name[i] == ' ') {}
		else
		{
			return 1;
		}
	}
	return 0;
}
char remove_new_line(char *name)
{
	int i = 0;

	for (i = 0; i < strlen(name); i++)
	{
		if (*(name + i) == '\n')
		{
			*(name + i) = '\0';
		}
	}

}