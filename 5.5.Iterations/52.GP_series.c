#pragma warning(disable:4996)

#include <stdio.h>
void get_numbers(int *first, int *nterms, int *common);
void get_numberofgp_series(int first, int nterms, int common);

int main()
{
	int numbers[3];
	get_numbers(&numbers[0], &numbers[1], &numbers[2]);
	get_numberofgp_series(numbers[0], numbers[1], numbers[2]);

	getch();
	return 0;
}
void get_numbers(int *first, int *nterms, int *common)
{
	printf("Input the first number of the G.P. series: ");
	scanf("%d", &(*first));

	printf("Input the number or terms in the G.P. series: ");
	scanf("%d", &(*nterms));

	printf("Input the common ratio of G.P. series: ");
	scanf("%d", &(*common));
}
void get_numberofgp_series(int first, int nterms, int common)
{
	int i = 0;
	int k = 1;
	int sum = 0;
	int s = 0;

	for (i = first; s<nterms; i = i * common)
	{
		printf("%d ", i);
		sum += i;
		s++;
	}
	printf("\nThe Sum of the G.P. series : %d", sum);

}