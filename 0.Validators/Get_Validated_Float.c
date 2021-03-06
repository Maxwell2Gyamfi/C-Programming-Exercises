#pragma warning(disable:4996)
#include <stdio.h>


float get_valid_float(int minumim, int maximum, float *value1)
{
	int success = 0;
	char buffer1[10];
	float value;
	int lenght = 0;
	int new_lenght = 0;

	char ch;

	while ((ch = getchar()) != '\n' && ch != EOF);


	do
	{
		fgets(buffer1, sizeof(buffer1), stdin);


		remove_new_line(buffer1);
		new_lenght = strlen(buffer1);

		if (has_not_dot(buffer1, new_lenght))
		{
			puts("A float has a (.)");
		}
		else if (isalpha_or_special_character(new_lenght, buffer1))
		{
			puts("No alphabets or special characters allowed");
		}
		else
		{
			sscanf(buffer1, "%f", &value);
			if ((value < minumim) || (value > maximum))
			{
				puts("Out of range");
			}
			else
			{

				success = 1;
				*value1 = value;
			}
		}
	} while (success == 0);
}
int has_not_dot(char *value, int lenght)
{
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if (value[i] == '.')
		{
			return 0;
		}
	}
	return 1;
}
int isalpha_or_special_character(int lenght, char *value)
{
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if ((isdigit(value[i])) || (value[i] == '.')) {}
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