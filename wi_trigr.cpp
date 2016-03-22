/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char mem[3];

int main(void)
{
	while((mem[2] = getchar()) != -1)
	{
		if(mem[0] == '?' && mem[1] == '?')
		{
			switch(mem[2])
			{
				case '=':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('#');
					break;

				case '/':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('\\');
					break;

				case '\'':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('^');
					break;

				case '(':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('[');
					break;

				case ')':
					mem[0] = mem[1] = mem[2] = 0;
					putchar(']');
					break;

				case '!':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('|');
					break;

				case '<':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('{');
					break;

				case '>':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('}');
					break;

				case '-':
					mem[0] = mem[1] = mem[2] = 0;
					putchar('~');
					break;

			}
		}

		if(mem[0])
			putchar(mem[0]);

		std::swap(mem[0], mem[1]);
		std::swap(mem[1], mem[2]);
	}

	putchar(mem[0]);
	putchar(mem[1]);
	return 0;
}

