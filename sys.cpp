/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

char res[16] = {
	'0',
	'1', 
	'2', 
	'3',
	'4',
	'5',
	'6',
	'7',
	'8',
	'9',
	'A',
	'B',
	'C',
	'D',
	'E',
	'F',
};

int tests,
	number,
	pos;

char result[1000000];

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &number);
		pos = 0;
		for(int num = number; num > 0; num /= 16)
			result[pos ++] = res[num % 16];

		-- pos;
		while(pos >= 0)
			printf("%c", result[pos --]);

		printf(" ");
		pos = 0;
		for(int num = number; num > 0; num /= 11)
			result[pos ++] = res[num % 11];

		--pos;
		while(pos >= 0)
			printf("%c", result[pos --]);

		puts("");	
	}
	return 0;
}
