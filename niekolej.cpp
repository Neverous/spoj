/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
int len;

int main(void)
{
	scanf("%d", &len);
	++ len;
	if(len == 1)
	{
		puts("0");
		return 0;
	}

	if(len < 4)
	{
		puts("NIE");
		return 0;
	}

	for(int p = 0, a = 0, b = len / 2; p < len; ++ p)
		printf("%d ", (p & 1)?(a ++):(b ++));

	puts("");
	return 0;
}

