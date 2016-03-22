/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int power;
long double ndpower[16384];

inline static long double ndPower(const unsigned int pow);

int main(void)
{
	while(scanf("%u", &power) != -1)
		printf("%.0Lf\n", ndPower(power));

	return 0;
}

inline static long double ndPower(const unsigned int pow)
{
	if(pow == 0)
		return 1;

	if(ndpower[pow] != 0)
		return ndpower[pow];

	ndpower[pow] = ndPower(pow / 2);
	ndpower[pow] *= ndpower[pow];
	if(pow % 2)
		ndpower[pow] *= 2;

	return ndpower[pow];
}
