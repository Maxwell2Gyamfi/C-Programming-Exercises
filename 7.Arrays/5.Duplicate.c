#pragma warning (disable:4996)

#include <stdio.h>
void get_duplicates(int *numbers);
int isduplicate(int *numbers, int m, int temp);

int main()
{
	int numbers[20];
	get_duplicates(numbers);

	getch();
	return 0;
}
void get_duplicates(int *numbers)
{
	int duplicate_numbers[20];
	int s,i,amount,temp=0;
	int k = 0;
	int duplicates = 0;
	int triplicate = 0;

	printf("Input the number of elements to be stored in the array : ");
	scanf("%d", &amount);

	printf("Input %d elements in the array : ",amount);
	printf("\n");
	for (i = 0; i < amount; i++)
	{
		printf("Element - %d : ", i + 1);
		scanf("%d", &numbers[i]);
		temp = numbers[i];

		if (isduplicate(numbers, i, temp))
		{
			duplicate_numbers[k] = temp;

			for (s = 0; s <=k; s++)
			{
				if (temp == duplicate_numbers[s])
					triplicate++;
			}
			if (triplicate > 1){}
			else duplicates++;
			k++;
		}
		triplicate = 0;
	}
	printf("\nTotal number of duplicate elements found in the array is : %d", duplicates);
}
int isduplicate(int *numbers, int m,int temp)
{
	int i = 0;

	for (i = m-1; i >=0; i--)
	{
		if (numbers[i] == temp)
		{
			return 1;
		}
	}
	return 0;
}