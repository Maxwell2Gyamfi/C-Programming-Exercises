
#pragma warning (disable:4996)


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGHT_NAME 16
#define MIN_LENGHT_NAME 2

int getvalidnumber(int minimum, int maximum);
char is_special_character(char * number);
char isalphabet(char * number);
int hasdot(char *number);
char get_valid_name(char *name);
int has_special_character_name(char *name);
char remove_new_line(char *name);
char yes_or_no();

struct Student *get_student_details(int *number_records);
int print_details(struct Student m[], int number_record);

typedef struct Student
{
	int studentid;
	int roll_number;
	char name[MAX_LENGHT_NAME];
	int marks[4];
	int total_marks;

}student;

int main()
{
	student *m;
	int number_records;

	m = get_student_details(&number_records);
	print_details(m,number_records);

	getch();
	return 0;
}
struct Student *get_student_details(int *number_records)
{
	static char buffer[10];
	int number_record =0;
	char choice = 0;
	int i = 0;
	int total = 0;
	student m[200];

	do
	{
		m[number_record].studentid = number_record+1;

		printf("Input the Roll Number of the student:");
		m[number_record].roll_number = getvalidnumber(1, 1000);
		printf("Input the Name of the Student:");
		get_valid_name(m[number_record].name);
		printf("Input the marks of Physics, Chemistry and Computer Application:");

		for (i = 0; i < 3; i++)
		{
			m[number_record].marks[i] = getvalidnumber(0, 1000);
			
			total += m[number_record].marks[i];
			
		}
		m[number_record].total_marks = total;

		fputs("Would you like to add another student record?(Y/N):",stdout);
		choice = yes_or_no();

		if (choice == 'Y')
		{
			number_record++;
		}

	} while (choice == 'Y');
	*number_records = number_record+1;
	return m;

}
int print_details(struct Student m[],int number_record)
{
	int i = 0;
	int j = 0;
	int studentid=0;
	int percentage = 0;

	printf("\nEnter the id of student: ");
	scanf("%d", &studentid);

	for (i = 0; i <= number_record; i++)
	{
		if (studentid == m[i].studentid)
		{
			m[i].name[0] = toupper(m[i].name[0]);
			printf("Name of Student: %s", m[i].name);
			printf("\nRoll No: %d ", m[i].roll_number);
			printf("\nMarks in Physics: %d", m[i].marks[0]);
			printf("\nMarks in Chemistry: %d", m[i].marks[1]);
			printf("\nMarks in Computer Application: %d", m[i].marks[2]);
			printf("\nTotal_marks = %d", m[i].total_marks);
			percentage = m[i].total_marks / 3;
			printf("\nPercentage = %.2f", (float)percentage);

			if (percentage >= 60)
			{
				printf("\nDivision = First");
				return 0;
			}
			else if (percentage < 60 && percentage >= 48)
			{
				printf("\nDivision = Second");
				return 0;
			}
			else
			{
				if (percentage < 48 && percentage >= 36)
				{
					printf("\nPass");
					return 0;
				}
				else
				{
					printf("\nFail");
					return 0;
				}
			}
		}
	}
	printf("Student Id not found");

}

int getvalidnumber(int minimum, int maximum)
{
	static char numbers[10];
	int success = 0;
	int number = 0;
	int ch;

	if (getchar == '\n')
	{
		while ((ch = getchar()) != '\n' && ch != EOF);
	}
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

char get_valid_name(char *name1)
{
	static char name[MAX_LENGHT_NAME + 1];
	int success = 0;
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
char yes_or_no()
{
	static char input;
	static char buffer[5];
	int success = 0;
	char ch;

	while ((ch = getchar()) != '\n' && ch != EOF);
	

	do
	{
		fgets(buffer, sizeof(buffer), stdin);
		remove_new_line(buffer);
		sscanf(buffer, "%c", &input);
		

		input = toupper(input);

		if ((input == 'Y') || (input == 'N'))
		{
			success = 1;
			return input;
		}
		else
		{
			fputs("Incorrect input, try again: ", stderr);
		}

	} while (success == 0);

}