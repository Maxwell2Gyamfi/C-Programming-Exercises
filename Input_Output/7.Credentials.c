#pragma warning (disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGHT_NAME 16
#define MIN_LENGHT_NAME 2

int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);

int get_valid_name(char *name);
int has_special_character_name(char *name);
char remove_new_line(char *name);

struct credentials *get_firstname();
struct credentials get_lastname(struct credentials *q);
struct credentials get_year_of_birth(struct credentials *q);
void print_credentials(struct credentials *q);


typedef struct credentials
{
	char *name;
	char *surname;
	int yearofbirth;

}Person;

int main()
{

	Person *person;

	person = get_firstname();
	get_lastname(person);
	get_year_of_birth(person);

	print_credentials(person);
	getch();

	return 0;
}

struct credentials *get_firstname()
{
	Person *m;
	
	m = (struct credentials *)malloc(MAX_LENGHT_NAME * sizeof(struct credentials));
	m->name = (char *)malloc(MAX_LENGHT_NAME* sizeof(char));

	printf("Enter your firstname: ");
	get_valid_name(m->name);

	return m;

}

struct credentials get_lastname(struct credentials *q)
{
	q->surname = (char *)malloc(MAX_LENGHT_NAME * sizeof(char));

	printf("Enter your surname: ");
	get_valid_name(q->surname);

}

struct credentials get_year_of_birth(struct credentials *q)
{
	printf("Input your year of birth: ");
	q->yearofbirth = getvalidnumber(1900, 2018);
}

void print_credentials(struct credentials *q)
{
	printf("%s %s %d", q->name,q->surname,q->yearofbirth);
}

int get_valid_name(char *name1)
{
	int success = 0;
	char name[MAX_LENGHT_NAME+1];
	
	do
	{
		fgets(name, sizeof(name), stdin);
		remove_new_line(name);

		int lenght = strlen(name);

		if (has_special_character_name(name))
		{
			fputs("Error special characters not allowed\n",stderr);
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
		
		if(isalpha(name[i])||name[i]==' '){}
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

	for (i = 0; i < strlen(name);i++)
	{
		if (*(name+i) == '\n')
		{
			*(name+i) = '\0';
		}
	}

}
int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;

	do {

		scanf("%s", numbers);

		if (hasdot(numbers))
		{
			printf("Floats not allowed\n");
		}
		else if (is_special_character(numbers))
		{
			printf("Special characters not allowed\n");
		}
		else if (isalphabet(numbers))
		{
			printf("Alphabets not allowed\n");
		}
		else
		{
			number = atoi(numbers);
			if ((number < minimum) || number > maximum)
			{
				printf("Out of range\n");
			}
			else
			{
				success = 1;
				return number;
			}
		}

	} while (success == 0);

}
int hasdot(char *number)
{
	int i = 0;
	int j = 0;


	for (j = 0; j < strlen(number); j++)
	{
		if (number[j] == '.')
		{
			return 1;
		}
	}
	return 0;

}
char is_special_character(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number);


	for (j = 0; j < lenght; j++)
	{
		if (isalpha(number[j]) || isdigit(number[j]) || number[j] == '-')
		{
			if ((lenght == 1) && (number[j] == '-'))
			{
				return 1;
			}
		}
		else
		{
			return 1;

		}
	}
	return 0;
}

char isalphabet(char * number)
{
	int i = 0;
	int j = 0;
	int lenght = strlen(number) - 1;


	for (j = 0; j <= lenght; j++)
	{
		if (isalpha(number[j]))
		{
			return 1;
		}
	}
	return 0;
}



