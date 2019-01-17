#pragma warning (disable:4996)
#include <stdio.h>

void make_decision(int age);
int get_age();

int main()
{
	int age=0;
	get_age();

	getch();
	return 0;
}
int get_age()
{
	int age1 = 0;
	char buffer[5];

	printf("Enter your age: ");
	fgets(buffer, sizeof(buffer), stdin);
	sscanf(buffer, "%d", &age1);

	make_decision(age1);
	
}
void make_decision(int age)
{

	if (age >= 18)
	{
		printf("Congratulation!You are eligible for casting your vote.");
	}
	else
	{
		fputs("Youre not elegible for casting",stdout);
	}

}