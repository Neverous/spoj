/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int number,
			 i = 52,
			 j = 52,
			 wins;
bool got[64];

int main(void)
{
	while(scanf("%u", &number) != -1)
		got[number] = true;

	while(i > 0 && j > 0)
	{
		while(i > 0 && !got[i])
			-- i;

		j = j>i?i:j;
		while(j > 0 && got[j])
			-- j;

		if(j > 0 && i > 0)
			++ wins;

		-- j;
		-- i;
	}

	printf("%u\n", wins);
	return 0;
}

