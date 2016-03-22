/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>

int tab[32] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 0, 200, 0, 300, 400, 500},
	result;
char buffer[32];

int main(void)
{
	scanf("%s", buffer);
	for(int b = 0; buffer[b]; ++ b)
		result += tab[buffer[b]-'a'];

	printf("%d\n", result);
	return 0;
}
