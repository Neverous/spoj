/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests;
int x, y, z;

inline static int ABS(int a);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%d %d %d", &x, &y, &z);
		printf("%d\n", (12 * (ABS(x + y - z*y)) + (z - 1) / 2) / (z - 1));
	}

	return 0;
}

inline static int ABS(int a)
{
	return a<0?-a:a;
}
