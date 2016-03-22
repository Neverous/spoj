/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 numbers,
			 size;

static inline void showMe(const unsigned int &alphabet, unsigned int rest, unsigned int act = 1, unsigned int used = 0);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &numbers, &size);
		showMe(numbers, size);
	}

	return 0;
}

static inline void showMe(const unsigned int &alphabet, unsigned int rest, unsigned int act, unsigned int used)
{
	if(!rest)
	{
		for(unsigned int a = 1; a <= alphabet; ++ a)
			if(used & (1 << a))
				printf("%u ", a);

		puts("");
		return;
	}

	showMe(alphabet, rest - 1, act + 1, used | (1 << act));
	if(alphabet - act < rest)
		return;

	showMe(alphabet, rest, act + 1, used);
	return;
}
