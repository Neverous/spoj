/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 numbers;
long long unsigned int number,
					   result;

long long unsigned int nwd(long long unsigned int a, long long unsigned int b);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		result = 1;
		scanf("%u", &numbers);
		for(unsigned int n = 0; n < numbers; ++ n)
		{
			scanf("%llu", &number);
			result = result / nwd(result, number) * number;
		}

		printf("%llu\n", result);
	}

	return 0;
}

long long unsigned int nwd(long long unsigned int a, long long unsigned int b)
{
	long long unsigned int c;
	if(a < b)
	{
		c = a;
		a = b;
		b = c;
	}

	while(b)
	{
		c = b;
		b = a % b;
		a = c;
	}

	return a;
}
