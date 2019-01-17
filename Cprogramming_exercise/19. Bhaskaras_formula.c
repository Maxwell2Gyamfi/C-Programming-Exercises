#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float* getroot(float numbers[]);
struct Rooter getroot2(float numbers[]);
 
typedef struct Rooter 
{
	float x;
	float y;
};

int main()
{   /////METHOD ONE
	/******************************************************************/
	float root1 = 0;
	float root2 = 0;
	float root = 0;


	float a = 0;
	float b = 0;
	float c = 0;

	printf("Enter a b and c: ");
	scanf("%f%f%f", &a, &b, &c);

	root = (b*b) - (4 * (a)*(c));

	if (a != 0 && root >0)
	{
		
		root = sqrt(root);
		root1 = ((b*-1) + root) / (2 * a);
		root2 = ((b*-1) - root) / (2 * a);
		printf("%f\n", root1);
		printf("%f", root2);
	}
	else
	{
		printf("Incorrect values");
	}
	///METHOD TWO WITH POINTER ARRAYS
	/*************************************************************/

	float numbers[5];
	float *roote = 0;
	int i = 0;

	printf("Enter a b c: ");
	
	for (i = 0; i < 3; i++)
	{
		scanf("%f", &numbers[i]);
		if (numbers[0] == 0)
		{
			printf("Invalid number a");
			return 0;
		}
	}
	roote = getroot(numbers);
	for (i = 0; i < 2; i++)
	{
	printf("%f\n", roote[i]);
	}
	///METHOD 3 WITH STRUCTS
	/****************************************************************/
	struct Rooter p;

	p = getroot2(numbers);

	printf("%f", p.x);
	printf("%f", p.y);
	
	getch();
	return 0;
}
float* getroot(float numbers[])
{
	
	static float roote[2];
	float root12 = 0;
	float root = 0;
	float root1 = 0;
	float root2 = 0;
	
	root = (numbers[1]*numbers[1]) - (4 * (numbers[0])*(numbers[2]));
	if (numbers[0] != 0 && root >0)
	{

		root = sqrt(root);
		root12 = ((numbers[1])*-1);

		root1 = (root12 + root) / (2 * numbers[0]);
		root2 = (root12 - root) / (2 * numbers[0]);
		roote[0]= root1;
		roote[1] = root2;

		return roote;
	}
}
struct Rooter getroot2(float numbers[])
{
    struct Rooter q;
	float roote[2];
	float root12 = 0;
	float root = 0;
	float root1 = 0;
	float root2 = 0;

	root = (numbers[1] * numbers[1]) - (4 * (numbers[0])*(numbers[2]));
	if (numbers[0] != 0 && root >0)
	{

		root = sqrt(root);
		root12 = ((numbers[1])*-1);

		root1 = (root12 + root) / (2 * numbers[0]);
		root2 = (root12 - root) / (2 * numbers[0]);
		q.x = root1;
		q.y = root2;

		return q;
	}
}
