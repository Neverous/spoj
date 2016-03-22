/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cmath>

int AE,
	BF,
	BG,
	h;

int main(void)
{
	scanf("%d %d %d %d", &AE, &BG, &BF, &h);
	printf("%0.2lf", (double)h + sqrt((long double)((long unsigned)(AE + BG) * (AE + BG) + (long unsigned)BF * BF)));
}
