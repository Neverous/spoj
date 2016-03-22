/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int Sx,
	Sy,
	r,
	points,
	x, y;

int main(void)
{
	scanf("%d %d %d", &Sx, &Sy, &r);
	r *= r;
	scanf("%d", &points);
	for(int p = 0; p < points; ++ p)
	{
		scanf("%d %d", &x, &y);
		x = (Sx - x) * (Sx - x) + (Sy - y) * (Sy - y);
		printf("%c\n", r == x?'E':r > x?'I':'O');
	}

	return 0;
}

