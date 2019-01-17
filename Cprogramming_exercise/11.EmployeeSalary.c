#pragma warning(disable :4996)

#include <stdio.h>
#include<string.h>
#include <ctype.h>

#define DOLLAR_SIGN 36

int *employee_id_check();
float salary();


int main()
{
	char *employee_id=0;//pointer employee id to an array return item
	float total_salary = 0;

	while(employee_id == 0)//while not valid
	{
		employee_id = employee_id_check();
	}

	total_salary = salary();

	printf("Employee ID = %s\n", employee_id);
	printf("Salary = U%c %.2f", DOLLAR_SIGN, total_salary);

	getchar();
	return 0;
}
int *employee_id_check()
{
	static char employee_id[10];//static because its local
	int correct = 0;
	int i = 0;

	int size = 0;
	int l = 0;

	    printf("Enter valid employee_id(Max 5 characters with at least 1 @): ");
	    scanf("%s", employee_id);
		size = strlen(employee_id);//saves size of inputed array

		if ((size < 5) || (size > 9))
		{
			printf("Wrong lenght\n");
			return 0;
		}

		for (int j = 0; j < 1; j++)//loop only 1 item in the array 
		{
			for (i = 0; i < 1; i++)//checks if the first character is a digit
			{
				if (isdigit(employee_id[0]))
				{
					for (int j = 0; j < (strlen(employee_id) - 1) && '@'; j++)//loops through the item and check for @
					{
						if ((employee_id[j]) == '@')
						{
							return employee_id;
						}
					}
					printf("@ Not found\n");
					return 0;
				}
				else
				{
					printf("Incorrect first digit\n");
					return 0;
				}
			}
		}	
}
float salary()
{
	int working_hours = 0;
	float salary_amount = 0;
	float total_salary = 0;
	
	printf("Input the working hours: ");
	scanf("%d", &working_hours);
	printf("Input salary amount/hr: ");
	scanf("%f", &salary_amount);
	
	total_salary = working_hours * salary_amount;
	return total_salary;
	

}
