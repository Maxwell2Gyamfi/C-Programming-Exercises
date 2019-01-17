#pragma warning(disable:4996)

#include <stdio.h>
int calculate_s();
int main()
{
	calculate_s();
	getch();



	return 0;
}
int calculate_s()
{
	float first_number = 3;
	float second_number = 2;
	int i = 0;
	float s = 0;
	float first = 1;

	    
	while (first_number < 7)
	{
		s += first + (first_number / second_number);
		first_number += 2;
		second_number += second_number;
	}
	
	printf("%f", s);


}