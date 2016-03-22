/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

char buffer[202];
int tests,
	count = 1;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%s", buffer);
		count = 1;
		for(int b = 1; buffer[b-1]; ++ b)
		{
			if(buffer[b] == buffer[b-1])
			{
				++ count;
				continue;
			}
			
			if(count > 2)
				printf("%c%d", buffer[b-1], count);

			else
				while(count--)
					printf("%c", buffer[b-1]);

			count = 1;
		}

		puts("");
	}

	return 0;
}
