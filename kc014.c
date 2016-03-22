/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<stdio.h>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int BUFFER = 4096,
	p = 4095,
	size,
	A[10][10],
	B[10][10],
	C[10][10],
	h, w, j;
char buffer[4096];

int getInt(void)
{
	int number = 0;
	if(!BUFFER)
		return -1;

	while(BUFFER && (buffer[p] < '0' || buffer[p] > '9') && ++ p)
		if(p == BUFFER)
		{
			BUFFER = fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while(BUFFER && buffer[p] >= '0' && buffer[p] <= '9')
	{
		number = number * 10 + buffer[p ++] - '0';
		if(p == BUFFER)
		{
			BUFFER = fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}
	}

	return number;
}

int main(void)
{
	while((size = getInt()) != -1)
	{
		for(h = 0; h < size; ++ h)
			for(w = 0; w < size; ++ w)
			{
				C[h][w] = 0;
				A[h][w] = getInt();
			}

		for(h = 0; h < size; ++ h)
			for(w = 0; w < size; ++ w)
				B[h][w] = getInt();

		for(h = 0; h < size; ++ h)
			for(w = 0; w < size; ++ w)
				for(j = 0; j < size; ++ j)
					C[h][w] += A[h][j] * B[j][w];

		for(h = 0; h < size; ++ h)
			for(w = 0; w < size; ++ w)
				printf("%d ", C[h][w]);

		puts("");
	}

	return 0;
}

