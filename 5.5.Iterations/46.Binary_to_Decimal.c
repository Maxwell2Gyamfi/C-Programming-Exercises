#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <math.h>

void get_binary();
char get_valid_binary(char *n, int *lenght);
int check_0_1(char *n, int lenght);
void get_sum(char *n, int lenght);

int main()
{

	get_binary();

	getch();
	return 0;
}
void get_binary()
{
	int lenght = 0;
	char binary[20];

	printf("Input the binary number : ");
	get_valid_binary(binary,&lenght);
	get_sum(binary, lenght);

}
char get_valid_binary(char *n,int *lenght)
{
	char binary[20];
	int success = 0;

	do
	{
		scanf("%s", binary);
		*lenght = strlen(binary);
	    
		if (check_0_1(binary,*lenght))
		{
			printf("\nOnly '0 and 1 are binary numbers, try again: ");
		}
		else
		{
			strcpy(n, binary);
			success = 1;
		}
	} while (success == 0);
}
int check_0_1(char *n,int lenght)
{
	int i = 0;

	for (i = 0; i < lenght; i++)
	{
		if (n[i] == '0' || n[i] == '1'){}
		else
		{
			return 1;
		}
	}
	return 0;
}
void get_sum(char *n,int lenght)
{
	int i = 0;
	int counter = 0;
	int sum = 0;
	int l = pow(2.0, (double)lenght - 1);

	for (i =l; i > 0; i = i / 2)
	{
		if (n[counter] == '1')
		{
			sum += i;
		}
		counter++;
	}
	printf("The binary number : %s", n);
	printf("\nThe equivalent Decimal Number is: %d ", sum);

}