#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

void get_key(int*n,int size);
int main()
{
	int i = 0;
	int size = 0;
	int elements[] = { 1,2,3,4,5,6,7,8,9,10 };
	size = sizeof(elements)/4;
	get_key(elements, size);
	

	getch();
	return 0;
}
void get_key(int*n, int size)
{
	int index = 0;
	int start = 0;
	int half = 0;
	int value = 0;
	int end = 0;
	int success = 0;

	printf("Enter value to look for: ");
	scanf("%d", &value);

	end = size - 1;

	while (start <= end)
	{
		    half = (start +end) / 2;
		
			if (n[half] == value)
			{
				index = half;
				printf("Element found at index %d", index+1);
				success = 1;
				break;

			}
			else
			{
				if (value > n[half])
				{
					start = half + 1;

				}
				else
				{
					end = half - 1;
				}
			}
		
	}
	if (success == 0)
	{
		printf("Element not found");
	}
}