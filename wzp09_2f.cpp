/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>

int result;
char buffer[1024];

int main(void)
{
	while(scanf("%s", buffer) != -1 && buffer[0] != '0')
	{
		result = 0;
		for(int b = 0; buffer[b]; ++ b)
			result = (result * 10 + buffer[b] - '0') % 15;

		puts(!result?"TAK":"NIE");
	}

	return 0;
}
