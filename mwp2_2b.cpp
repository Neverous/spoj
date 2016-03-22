/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int n,
	pow,
	MOD;

inline static const int fastPower(const int &n, const int &pow, const int &MOD);

int main(void)
{
	while(scanf("%d %d %d", &n, &pow, &MOD) != -1 && (n || pow || MOD))
		printf("%d\n", fastPower(n % MOD, pow, MOD));

	return 0;
}

inline static const int fastPower(const int &n, const int &pow, const int &MOD)
{
	if(!pow)
		return 1;

	int res = fastPower(n, pow / 2, MOD);
	res *= res;
	if(res >= MOD)
		res %= MOD;

	if(pow % 2)
		res *= n;

	if(res >= MOD)
		res %= MOD;

	return res;
}
