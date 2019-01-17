#pragma warning(disable:4996)
#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int get_pell_series(int range, int numbers[]);
int main()
{
	int numbers[20];
	numbers[0] = 0;
	numbers[1] = 1;
	get_pell_series(0,&numbers);
	getch();
	return 0;
}
int get_pell_series(int range,int numbers[])
{
	 int *k = &numbers[0];
	 int pell_number = 0;

	 if (range == 20)
	 {
		return 1;
	 }
	else
	{
		 if (range == 0)printf("%d ", numbers[range]);
         else if (range == 1)printf("%d ", k[range]);
		 else
		 {
			 pell_number = (2 * (numbers[range - 1])) + (numbers[range - 2]);
			 k[range] = pell_number;
			 printf("%d ", pell_number);
		 }
		 get_pell_series(range + 1, k);
	}

}