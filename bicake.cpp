/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<cmath>

long long int number;

inline static const long long int MAX(const long long int &a, const long long int &b){return a>b?a:b;}
int main(void)
{
	while(scanf("%lld", &number) != -1)
		printf("%lld\n", MAX((long long int)floor((1.0 + sqrtl(1.0 + 8.0 * (number - 2))) / 2), 0));

	return 0;
}
