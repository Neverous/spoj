/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

unsigned int tests,
			 numbers,
			 number,
			 count[1024],
			 max;

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		for(unsigned int n = 0; n < 1024; ++ n)
			count[n] = 0;

		scanf("%u", &numbers);
		for(unsigned int n = 0; n < numbers; ++ n)
		{
			scanf("%u", &number);
			++ count[number];
		}

		max = 1023;
		while(!count[max])
			-- max;

		while(count[max])
		{
			printf("%u ", max);
			-- count[max];
		}

		for(unsigned int n = 0; n < max; ++ n)
			while(count[n])
			{
				printf("%u ", n);
				-- count[n];
			}

		puts("");
	}

	return 0;
}

