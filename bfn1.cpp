/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define isPalindrome(num) (number == reversed(number))

unsigned int tests,
			 number,
			 steps;

inline static unsigned int reversed(unsigned int num);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u", &number);
		steps = 0;
		while(!isPalindrome(number))
		{
			number += reversed(number);
			++ steps;
		}

		printf("%u %u\n", number, steps);
	}

	return 0;
}

inline static unsigned int reversed(unsigned int num)
{
	unsigned int res = 0;
	while(num)
	{
		res = res * 10 + num % 10;
		num /= 10;
	}

	return res;
}
