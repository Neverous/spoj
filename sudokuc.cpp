/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int tests,
	matrix[16][16];
bool was[10];

bool solve(void);

int main(void)
{
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		for(int h = 0; h < 9; ++ h)
			for(int w = 0; w < 9; ++ w)
				scanf("%d", &matrix[h][w]);

		printf("%s\n", solve()?"TAK":"NIE");
	}

	return 0;
}

bool solve(void)
{
	/* 1ST PHASE */
	for(int h = 0; h < 9; ++ h)
		for(int w = 0; w < 9; ++ w)
			if(matrix[h][w] < 1 || matrix[h][w] > 9)
				return false;

	/* 2ND PHASE */
	for(int h = 0; h < 9; ++ h)
	{
		for(int d = 1; d <= 9; ++ d)
			was[d] = false;

		for(int w = 0; w < 9; ++ w)
		{
			if(was[matrix[h][w]])
				return false;

			was[matrix[h][w]] = true;
		}
	}

	for(int w = 0; w < 9; ++ w)
	{
		for(int d = 1; d <= 9; ++ d)
			was[d] = false;

		for(int h = 0; h < 9; ++ h)
		{
			if(was[matrix[h][w]])
				return false;

			was[matrix[h][w]] = true;
		}
	}

	/* 3RD PHASE */
	for(int H = 0; H < 3; ++ H)
		for(int W = 0; W < 3; ++ W)
		{
			for(int d = 1; d <= 9; ++ d)
				was[d] = false;

			for(int h = 0; h < 3; ++ h)
				for(int w = 0; w < 3; ++ w)
				{
					if(was[matrix[H * 3 + h][W * 3 + w]])
						return false;

					was[matrix[H * 3 + h][W * 3 + w]] = true;
				}
		}

	return true;
}
