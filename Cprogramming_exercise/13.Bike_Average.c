#pragma warning(disable:4996)

#include <stdio.h>
float calculate_average_consumptions(int total_distance, float spent_fuel);

int total_distance = 0;
float spent_fuel = 0;
float average_cons = 0;

int main()
{
	printf("Input total distance in km: ");
	scanf("%d", &total_distance);
	printf("Input total fuel spent in liters: ");
	scanf("%f", &spent_fuel);

	average_cons=calculate_average_consumptions(total_distance, spent_fuel);
	printf("Average consumption (km/lt) %2.3f", average_cons);

	getch();
	return 0;
}
float calculate_average_consumptions(int total_distance, float spent_fuel)
{
	average_cons = total_distance / spent_fuel;

	return average_cons;

}