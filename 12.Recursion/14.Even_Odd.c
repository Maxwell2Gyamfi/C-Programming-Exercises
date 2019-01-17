#pragma warning(disable:4996)
#include <stdio.h>
int get_range();
int get_even_odd(int n, int i, int *k, int *s, int l, int m);
void print_even_odd(int count, int *s, int k);
int main()
{
	int i = 1;
	int even[500];
	int odd[500];
	int end = get_range();
	get_even_odd(end, i, even, odd,0,0);

	getch();
	return 0;
}
int get_range()
{
	int n = 0;
	printf("Input the range to print starting from 1: ");
	scanf("%d", &n);
	return n;

}
int get_even_odd(int n,int i,int *k,int *s,int l,int m)
{
	if (i>n)
	{
		print_even_odd(n, k,1);
		print_even_odd(n, s, 0);
		return 1;
	}
	else
	{
		if (i % 2 == 0) k[l++] = i;
		else s[m++] = i;
		get_even_odd(n, i + 1, k, s, l,m);
	}
}
void print_even_odd(int count, int *s,int k)
{
	int i = 0;

	k == 1 ? printf("All even numbers from 1 to %d are : ", count) :
		printf("\n\nAll odd numbers from 1 to %d are : ", count);

	for (i = 0; i <count/2; i++)
	{
		printf("%d ",s[i]);
	}
}