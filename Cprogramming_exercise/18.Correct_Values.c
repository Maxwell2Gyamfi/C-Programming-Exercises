#pragma warning (disable:4996)
#include <stdio.h>
#include <string.h>

char* correct_values(int p, int q, int r, int s);

int main()
{
	char* correct_response;

	int r = 0;
	int s = 0;
	int p = 0;
	int q = 0;

	
	printf("Enter the integers (p,q,r,s): ");
	scanf("%d%d%d%d", &p, &q, &r, &s);

	correct_response = correct_values(p, q, r, s);

	printf("%s", correct_response);

	getch();
	return 0;
}
char* correct_values(int p, int q, int r, int s)
{
	static char wrong[] = "Wrong values";
	static char correct[] = "Correct values";

	if (p % 2 == 0)
	{
		if (r && s > 0)
		{
			if ((q > r) && (s > p) && ((r + s) > (p + q)))
			{
				return correct;
			}
		}
	}
	return wrong;
}