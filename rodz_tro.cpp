/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int t[3];

int main(void)
{
	while(scanf("%d %d %d", &t[0], &t[1], &t[2]) != -1)
	{
		std::sort(t, t + 3);
		if(t[0] + t[1] <= t[2])
			puts("brak");

		else
			printf("%sokatny\n", (t[0]*t[0] + t[1]*t[1] == t[2]*t[2])?"prost":(t[0]*t[0] + t[1]*t[1] < t[2]*t[2])?"rozwart":"ostr");
	}

	return 0;
}

