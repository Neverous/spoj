/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
	number,
	result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &number);
		result = 0;
		while(number)
			result += number /= 5;

		printf("%d\n", result);
	}

	return 0;
}
