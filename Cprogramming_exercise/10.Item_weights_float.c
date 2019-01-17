#pragma warning (disable: 4996)

#include <stdio.h>

float itemdetails(float firstitemweigth, float seconditemweigth, float quantity1, float quantity2);

int main()
{
	float average_value = 0;
	float firstitemweigth=0; 
	float seconditemweigth=0; 
	float quantity1=0; 
	float quantity2 = 0;

	printf("Enter item one weight and number of item 1: ");
	scanf("%f%f", &firstitemweigth, &quantity1);

	printf("Enter item two weight and number of item 2: ");
	scanf("%f%f", &seconditemweigth, &quantity2);

   
	average_value = itemdetails(firstitemweigth, seconditemweigth, quantity1, quantity2);
	printf("Average value %f: ", average_value);
	getch();
	return 0;
}
float itemdetails(float firstitemweigth, float seconditemweigth, float quantity1, float quantity2)
{
	float averagevalue = 0;
	float averagecost = 0;
	averagecost = ((firstitemweigth * quantity1) + (seconditemweigth*quantity2)) / (quantity1 + quantity2);


	return averagevalue;
}