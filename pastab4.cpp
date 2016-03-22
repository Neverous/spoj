/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define WIDTH 30

int num,
	count[32],
	max;

int main(void)
{
	while(scanf("%d", &num) != -1)
		++ count[num + 10];

	for(int n = 0; n < 21; ++ n)
		max = max > count[n]?max:count[n];

	if(max > 0)
	for(int n = 0, ile; n < 21; ++ n)
	{
		printf("%4d:|", n - 10);
		ile = (WIDTH * count[n] + max / 2) / max;
		for(int w = 1; w <= WIDTH; ++ w)
			putchar(w <= ile?'*':' ');

		puts("|");
	}

	return 0;
}

