/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 length,
			 ciphered[32],
			 prime[5] = {127, 131, 137, 139, 149},
			 good[5],
			 g;
bool solve(unsigned int key, bool print = true);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		g = 0;
		scanf("%u", &length);
		for(unsigned int l = 0; l < length; ++ l)
			scanf("%u", &ciphered[l]);

		for(unsigned int k = 0; k < 5 && g < 2; ++ k)
			if(solve(k, false))
				good[g ++] = k;

		if(!g || g > 1)
			puts("NIECZYTELNE");

		else
			solve(good[0]);
	}

	return 0;
}

bool solve(unsigned int key, bool print)
{
	unsigned int deciphered[32];
	for(unsigned int l = 0; l < length; ++ l)
		if((deciphered[l] = ciphered[l] % prime[key]) < 'A' || deciphered[l] > 'Z')
			return false;

	if(!print)
		return true;

	printf("%u ", prime[key]);
	for(unsigned int l = 0; l < length; ++ l)
		putchar(deciphered[l]);

	puts("");
	return true;
}
