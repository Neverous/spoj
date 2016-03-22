/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

char buffer[32];
int tests;

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%s", buffer);
		for(int b = 0; buffer[b]; ++ b)
			switch(buffer[b])
			{
				case 'A':
				case 'B':
				case 'C':
					printf("2");
					break;

				case 'D':
				case 'E':
				case 'F':
					printf("3");
					break;

				case 'G':
				case 'H':
				case 'I':
					printf("4");
					break;

				case 'J':
				case 'K':
				case 'L':
					printf("5");
					break;

				case 'M':
				case 'N':
				case 'O':
					printf("6");
					break;

				case 'P':
				case 'Q':
				case 'R':
				case 'S':
					printf("7");
					break;

				case 'T':
				case 'U':
				case 'V':
					printf("8");
					break;

				case 'W':
				case 'X':
				case 'Y':
				case 'Z':
					printf("9");
					break;
			}

		puts("");
	}
	return 0;
}

