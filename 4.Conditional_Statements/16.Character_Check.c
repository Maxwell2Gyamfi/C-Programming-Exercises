#pragma warning(disable:4996)
#include <stdio.h>
#include <ctype.h>

char *get_character();
void character_check(char *character1);
char remove_new_line(char *character1);

int main()
{
	char *character;
	character = get_character();
	character_check(character);

	getch();
	return 0;
}
char *get_character()
{

	static char character1[5];
	static char buffer[5];

	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%s", character1);
	

	return character1;

	
}
void character_check(char *character1)
{
	size_t i;

	for (i = 0; i < strlen(character1); i++)
	{
		if (isalpha(character1[i]))
		{
			printf("Its an alphabet\n");
		}
		else if (isdigit(character1[i]))
		{

			printf("Its a digit\n");
		}
		else
		{
			printf("Its a special character\n");
		}

	}
}
char remove_new_line(char *character1)
{
	size_t i;
	for (i = 0; i <=strlen(character1); i++)
	{
		if (character1[i] == '\n')
		{
			*(character1 + i) = '\0';
		}
	}
}