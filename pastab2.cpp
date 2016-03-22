/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int tab[1001],
	numbers,
	border;

char cond[4];

int main(void)
{
	scanf("%d", &numbers);
	for(int n = 0; n < numbers; ++ n)
		scanf("%d", &tab[n]);

	scanf("%s%d", cond, &border);
	for(int n = 0; n < numbers; ++ n)
	{
		if((cond[0] == '<' && tab[n] < border) ||
				(cond[0] == '>' && tab[n] > border))
			printf("%d\n", tab[n]);
	}
	
	return 0;
}
