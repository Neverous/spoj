#include<cstdio>

const int BUFFER = 4096;
int p = BUFFER - 1;
char buffer[BUFFER];

int getNumber(void);

int number,
	numbers,
	dividers[8000008];
bool first;
inline void eratostenes(void);

int main(void)
{
	eratostenes();
	numbers = getNumber();
	for(int n = 0; n < numbers; ++ n)
	{
		number = getNumber();
		printf("%d", dividers[number]);
		number /= dividers[number];
		while(number > 1)
		{
			printf("*%d", dividers[number]);
			number /= dividers[number];
		}

		puts("");
	}

	return 0;
}

inline void eratostenes(void)
{
	for(int d = 0; d < 8000008; ++ d)
		dividers[d] = d;

	dividers[0] = 1;
	for(int i = 2; i * i <= 8000004; ++ i)
	{
		if(dividers[i] != i)
			continue;

		for(int j = i * i; j <= 8000004; j += i)
			if(dividers[j] == j)
				dividers[j] = i;
	}
}

int getNumber(void)
{
	int number = 0;
	while((buffer[p] < '0' || buffer[p] > '9') && ++ p)
		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while(buffer[p] >= '0' && buffer[p] <= '9')
	{
		number = number * 10 + buffer[p] - '0';
		++ p;
		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}
	}

	return number;
}

