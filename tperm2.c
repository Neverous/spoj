/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<stdio.h>
#include<stdlib.h>

int te,
	si,
	da[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'},
	d,
	t,
	*p, *p2, c,
	*s, *e,
	r[9];
char *re[9];

int sil(int a){return !a?1:sil(a-1)*a;}
void sw(int *a, int *b){c = *a;*a = *b;*b = c;}
void rev(int *st, int *en){s = st;e = en;while(s < e)sw(s ++, e --);}
int nP(int *st, int *en)
{
	p2 = 1 + (p = en);
	while(p > st && *(p - 1) >= *p)-- p;
	if(p == st){rev(st, en);return 0;}
	while(p2 > st && *(p2 - 1) <= *(p - 1))-- p2;
	sw(p - 1, -- p2);rev(p, en);
	return 1;
}

int main(void)
{
	scanf("%d", &te);
	for(t = 0; t < te; ++ t)
	{
		scanf("%d", &si);
		if(!si)continue;
		if(!re[si - 1])
		{
			re[si - 1] = (char*)malloc((1 + 11 * sil(si)) * sizeof(char));
			do
			{
				for(d = 0; d < si; ++ d)
					re[si - 1][r[si - 1] ++] = da[d];

				re[si - 1][r[si - 1] ++] = '\n';
			}
			while(nP(da, da + si - 1));
		}
		puts(re[si - 1]);
	}

	return 0;
}
