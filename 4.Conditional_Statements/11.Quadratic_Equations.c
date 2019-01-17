#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>
#include <math.h>

struct Quadratic get_numbers();
void get_solution(struct Quadratic *numbers);
void print_solution(struct Quadratic p);

typedef struct Quadratic
{

	int a;
	int b;
	int c;
	char answer[20];
	int error;

}P;


int main()
{
	P numbers;
	numbers = get_numbers();
	get_solution(&numbers);
	print_solution(numbers);

	getch();
	return 0;

}
struct Quadratic get_numbers()
{
	P numbers;

	printf("Enter a b and c: ");
	scanf("%d%d%d", &numbers.a, &numbers.b, &numbers.c);

	return numbers;
}
void get_solution(struct Quadratic *numbers)
{
	int b=0;
	int temp;
	int x1, x2 = 0;
	static char buffer1[3];
	static char buffer2[3];
	b = 2 * numbers->a;

	temp = pow((double)numbers->b, 2) - (4 * numbers->a * numbers->c);
	
	if (temp == 0)
	{

		printf("Both roots are equal.\n");

		x1 = (numbers->b*-1)/b;
		x2 = x1;

		sprintf(buffer1, "%d %d", x1,x2);
		strcpy(numbers->answer, buffer1);
		numbers->error = 1;
	}
	else if(temp>0)
	{
		printf("Both roots are real and diff-2\n");

		x1 = ((numbers->b*-1) + ((sqrt((double)temp))))/b;
		x2 = ((numbers->b*-1) - ((sqrt((double)temp)))) / b;

		sprintf(buffer1, "%d %d", x1,x2);
		strcpy(numbers->answer,buffer1);
		numbers->error = 1;

	}
	else
	{
		printf("Root are immaginary;\nNo Solution.\n");
	}
}
void print_solution(struct Quadratic p)
{
	int x1, x2 = 0;

	if (p.error == 1)
	{
		sscanf(p.answer, "%d %d", &x1, &x2);

		printf("x1 = %d\n x2 = %d", x1, x2);
		
	}
}