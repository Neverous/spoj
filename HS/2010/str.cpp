/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define ORD(arg) ((arg) - '0')

unsigned int tests,
			 size;
char word[64];

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %s", &size, word);
		for(unsigned int s = 0; s < size; ++ s)
			putchar(10 * (ORD(word[s * 4]) + ORD(word[s * 4 + 1])) +
				ORD(word[s * 4 + 2]) + ORD(word[s * 4 + 3]));

		puts("");
	}

	return 0;
}

