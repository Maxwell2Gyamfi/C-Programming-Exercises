#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>

int get_octal();
void convert_octal(int n);
int get_numberof_digits(int n);
int get_valid_octal();

int main()
{
	int n = 0;
	n = get_octal();
	convert_octal(n);

	getch();
	return 0;
}
int get_octal()
{
	int n = 0;

	printf("Input an octal number (using digit 0 - 7) : ");
	n = get_valid_octal();

	return n;
}
void convert_octal(int n)
{
	int i = 0;
	int l = 0;
	int result = 0;
	char buffer[10];
	int k = 0;

	sprintf(buffer, "%d", n);
	l = get_numberof_digits(n);
	k = l-1;
    
	for (i =0; i<l; i++)
	{
		result += ((buffer[i] - '0')*pow(8.0,(double)k));
		k--;
	}
	printf("\nThe octal number: %d", n);
	printf("\nThe equivalent Decimal Number: %d", result);

}
int get_numberof_digits(int n)
{
	int i = 0;
	int j = 0;

	for (i = n; n > 0; i++)
	{
		n = n / 10;
		j++;
	}
	return j;
}
int get_valid_octal()
{
	char buffer[10];
	int lenght = 0;
	int success = 0;
	int i = 0;
	int number = 0;
	
	do
	{
		scanf("%s", buffer);
		lenght = strlen(buffer);

		for (i = 0; i < lenght; i++)
		{
			number = buffer[i] - '0';
			if (number < 0 || number > 7)
			{
				printf("Error, input an octal number (using digit 0 - 7) : ");
				success = 0;
				break;
			}
			else
			{
				if (i == lenght - 1)
				{
					success = 1;
					sscanf(buffer, "%d", &number);
					return number;
				}
			}
		}
	} while (success == 0);

}