/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<cmath>

int tests,
	xa, ya, r0,
	xb, yb, r1;

inline static const long double MAX(const long double &a, const long double &b){return a>b?a:b;}
inline static const long double MIN(const long double &a, const long double &b){return a<b?a:b;}
inline static const long double dist(const int &x0, const int &y0, const int &x1, const int &y1);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d %d %d %d %d", &xa, &ya, &r0, &xb, &yb, &r1);
		printf("%.2Lf\n", MAX(MIN(2 * r0, 2 * r1) - MAX(dist(xa, ya, xb, yb) - MAX(r0, r1) + MIN(r0, r1), 0), 0));
	}

	return 0;
}

inline static const long double dist(const int &x0, const int &y0, const int &x1, const int &y1)
{
	return sqrtl((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}
