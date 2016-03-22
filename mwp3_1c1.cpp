/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int tests,
	a[131072], b[131072],
	res[131072],
	prime[1048576],
	max;

inline static const int MAX(const int &a, const int &b){return a>b?a:b;}
inline static void eratostenes(const int &max);
inline static const int nwd(const int &a, const int &b);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &a[t], &b[t]);
		if(a[t] == b[t])
			max = MAX(a[t], max);
		else
			res[t] = nwd(a[t], b[t]);
	}

	eratostenes(max);
	for(int t = 0; t < tests; ++ t)
		printf("%d\n", res[t]?res[t]:a[t]/prime[a[t]]);

	return 0;
}

inline static const int nwd(const int &a, const int &b)
{
	if(a < b)
		return nwd(b, a);

	if(!b)
		return a;

	return nwd(b, a % b);
}

inline static void eratostenes(const int &max)
{
	prime[0] = 1;
	prime[1] = 1;
	prime[2] = 2;
	for(int n = 4; n <= max; n += 2)
		if(!prime[n])
			prime[n] = 2;

	for(int p = 3; p * p <= max; p += 2)
	{
		if(prime[p])
			continue;

		prime[p] = p;
		for(int n = p * p; n <= max; n += p)
			if(!prime[n])
				prime[n] = p;
	}

	for(int p = 3; p <= max; p += 2)
		if(!prime[p])
			prime[p] = p;

	return;
}
