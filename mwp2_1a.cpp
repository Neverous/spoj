/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
	numbers,
	seq[128],
	best, result,
	count;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &numbers);
		for(int n = 0; n < numbers; ++ n)
			scanf("%d", &seq[n]);

		best = 0;
		result = 0;
		for(int m = 0; m < numbers; ++ m)
		{
			count = 0;
			for(int n = 0; n < numbers; ++ n)
				count += seq[(n + m) % numbers] == n + 1;

			if(count > best)
			{
				best = count;
				result = m;
			}
			
		}

		for(int n = 0; n < numbers; ++ n)
			printf("%d ", seq[(n + result) % numbers]);

		puts("");
	}

	return 0;
}
