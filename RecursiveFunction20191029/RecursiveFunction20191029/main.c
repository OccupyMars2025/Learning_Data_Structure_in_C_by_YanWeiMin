#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int g(int m, int n);
int F(int n);
double sqrt(double A, double p, double e);

int main()
{
	/*
	int value = g(5, 2);
	printf("\nvalue = %d", value);
	*/

	/*
	int i;

	for (i = 0; i < 20; i++)
	{
		printf("\nF(%d) = %d", i, F(i));
	}
	*/

	double result;

	result = sqrt(2.0, 100.0, 1e-8);
	printf("\nresult = %lf", result);

	return 0;
}

int g(int m, int n)
{
	if (m == 0 && n >= 0)
		return 0;
	else if (m > 0 && n >= 0)
		return g(m - 1, 2 * n) + n;
	else
		return 0;
}

int F(int n)
{
	if (n > 0)
		return n * F(n / 2);
	else if (n == 0)
		return n + 1;
	else
		return 0;
}

double sqrt(double A, double p, double e)
{
	static long long count = 0;

	if (A <= 0 || p <= 0 || e <= 0)
	{
		printf("\ninvalid parameters!!!");
		exit(1);
	}
	if (fabs(p * p - A) < e)
	{
		printf("\ncount = %lld", count);
		return p;
	}
	else
	{
		count++;
		return sqrt(A, 1.0 / 2 * (p + A / p), e);
	}
}