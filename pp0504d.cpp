/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 number;
char res[16];

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%f", &number); // to jest genialne ^^
		sprintf(res, "%08x", number);
		for(int r = 0; r < 8; ++ r)
		{
			if(r & 1 || res[r] != '0')
				putchar(res[r]);

			if(r & 1)
				putchar(' ');
		}

		putchar('\n');
	}

	return 0;
}

