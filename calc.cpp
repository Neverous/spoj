/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

char buffer[128];
int tests,
	result;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%s", buffer);
		result = 0;
		for(int b = 0, action = 0; buffer[b]; ++ b)
			if(b%2)
				action = buffer[b] == '-';

			else
				result = result + (action?-1:1) * (buffer[b] - '0');

		printf("%d\n", result);
	}

	return 0;
}

