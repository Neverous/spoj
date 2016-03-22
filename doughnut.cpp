/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int tests,
	cats,
	max,
	doughnut;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d %d", &cats, &max, &doughnut);
		printf("%s\n", cats * doughnut > max?"no":"yes"); 
	}
	return 0;
}
