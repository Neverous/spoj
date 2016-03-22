/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int tests,
	people,
	doughnuts,
	time,
	result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		result = 0;
		scanf("%d %d", &people, &doughnuts);
		for(int p = 0; p < people; ++ p)
		{
			scanf("%d", &time);
			result += 86400 / time;
		}

		printf("%d\n", (result + doughnuts - 1) / doughnuts);
	}
}
