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

	int i = 0;
	float s = 0;
	float first = 1;

	for (i = 1; i <= 50; i++)
	{
		s += first/ i;
	}
	printf("%f", s);
	

}