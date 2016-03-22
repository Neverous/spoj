/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...) 

struct Gcd
{
	int x,
		y,
		gcd;

	Gcd(int X = 1, int Y = 0, int GCD = 1)
	{
		x = X;
		y = Y;
		gcd = GCD;
	}
};

Gcd extGcd(int a, int b)
{
	int c;
	Gcd result;
	if(b)
	{
		result = extGcd(b, a % b);
		c = result.x;
		result.x = result.y;
		result.y = c - result.y * (a / b);
	}

	return result;
}

int tests,
	prime,
	number;

Gcd result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &prime, &number);
		result = extGcd(prime, number);
		if(result.y < 0)
			result.y -= ((result.y - prime + 1) / prime) * prime;

		printf("%d\n", result.y);
	}

	return 0;
}

