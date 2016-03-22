/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int size;

int main(void)
{
	while(scanf("%d", &size) != -1 && size)
	{
		if(size > 0)
		{
			for(int h = 1; h <= size; ++ h)
			{
				for(int w = 0; w < h; ++ w) putchar('*');
				for(int w = 0; w < size - h; ++ w) putchar('.');
				for(int w = 0; w < size + 1 - h; ++ w) putchar('*');
				for(int w = 0; w < h - 1; ++ w) putchar('.');
				puts("");
			}

			for(int h = 1; h <= size; ++ h)
			{
				for(int w = 0; w < size - h; ++ w) putchar('.');
				for(int w = 0; w < h; ++ w) putchar('*');
				for(int w = 0; w < h - 1; ++ w) putchar('.');
				for(int w = 0; w < size + 1 - h; ++ w) putchar('*');
				puts("");
			}
		}

		else
		{
			size = -size;
			for(int h = 1; h <= size; ++ h)
			{
				for(int w = 0; w < h - 1; ++ w) putchar('.');
				for(int w = 0; w < size + 1 - h; ++ w) putchar('*');
				for(int w = 0; w < size  - h; ++ w) putchar('.');
				for(int w = 0; w < h; ++ w) putchar('*');
				puts("");
			}

			for(int h = 1; h <= size; ++ h)
			{
				for(int w = 0; w < size + 1 - h; ++ w) putchar('*');
				for(int w = 0; w < h - 1; ++ w) putchar('.');
				for(int w = 0; w < h; ++ w) putchar('*');
				for(int w = 0; w < size - h; ++ w) putchar('.');
				puts("");
			}
		}
	}
	return 0;
}
