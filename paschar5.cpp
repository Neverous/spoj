/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char c;

int main(void)
{
	while((c = getchar()) != -1)
	{
		if(c <= '9' && c >= '0')
			c = (c - '0' + 5) % 10 + '0';

		else if(c <= 'z' && c >= 'a')
			c = (c - 'a' + 13) % 26 + 'a';

		else if(c <= 'Z' && c >= 'A')
			c = (c - 'A' + 13) % 26 + 'A';

		putchar(c);
	}

	return 0;
}

