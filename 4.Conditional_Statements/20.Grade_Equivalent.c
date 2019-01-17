#pragma warning(disable:4996)

#include <stdio.h>
#include <ctype.h>

char get_grade();
void get_equivalent(char grade);

int main()
{
	char grade = 0;
	grade=get_grade();
	get_equivalent(grade);

	getch();
	return 0;
}
char get_grade()
{
	int ch=0;
	char grade;

	printf("Enter grade: ");
	scanf("%c", &grade);

	return grade;
}
void get_equivalent(char grade)
{
	grade = toupper(grade);

	switch (grade)
	{
	case 'A':
		printf("Average");
		break;
	case 'E':
		printf("Excellent");
		break;
	case 'V':
		printf("Very good");
		break;
	case 'G':
		printf("Good");
		break;
	case 'F':
		printf("Fail");
		break;
	default:
		printf("Wrong input\n");
	}
}