/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

unsigned int tests,
			 contestants,
			 rest;
char c;

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		rest = 0;
		scanf("%u ", &contestants);
		while((c = getchar()) != -1 && c >= '0' && c <= '9')
			rest = (rest * 10 + c - '0') % contestants;

		puts(rest?"NIE":"TAK");
	}

	return 0;
}

