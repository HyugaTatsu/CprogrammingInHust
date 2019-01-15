#include <stdio.h>
void printPrimeNumber(int n)
{
	for (int i = 2; i <=n ; i++)
	{
		int temp = 0;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				temp++;
				break;
			}
		}
		if (temp == 0) printf("%d\t", i);
	}
	printf("\n");
}

void printPerfectNumber(int n)
{
	for (int i = 2; i <= n; i++)
	{
		int temp = 1;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) temp += j;
			if (temp > i) break;
		}
		if (temp == i) printf("%d\t", i);
	}
	printf("\n");
}

int main()
{
	int n;
	printf("Please insert the number n: ");
	scanf("%d", &n);
	printf("The list of prime number is: \n");
	printPrimeNumber(n);
	printf("The list of perfect number is: \n");
	printPerfectNumber(n);
}
