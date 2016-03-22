/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>

int square[32768],
	squareSize = 1,
	cube[1024],
	cubeSize = 1,
	tetra[256],
	tetraSize = 1;

void generatePowers(void); // Wypełnij powyższe tabelki
unsigned int solutions(int number); // Zwróć ilość rozwiązań równania

int tests,
	number;

int main(void)
{
	generatePowers();
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d", &number);
		printf("%u\n", solutions(number));
	}
	return 0;
}

void generatePowers(void)
{
	int sqrt;
	for(int n = 1; n < 32768; ++ n)
	{
		sqrt = n;
		if(sqrt <= 1000000000 / n)
		{
			sqrt *= n;
			square[squareSize ++] = sqrt;
			if(sqrt <= 1000000000 / n)
			{
				sqrt *= n;
				cube[cubeSize ++] = sqrt;
				if(sqrt <= 1000000000 / n)
					tetra[tetraSize ++] = sqrt * n;
			}
		}
	}
	return;
}

unsigned int solutions(int number) // O(tetraSize * cubeSize * log(squareSize))
{
	unsigned int result = 0;
	for(int t = 0; t < tetraSize && tetra[t] <= number; ++ t)
		for(int c = 0; c < cubeSize && tetra[t] + cube[c] <= number; ++ c)
			result += std::upper_bound(square, square + squareSize, number - tetra[t] - cube[c]) - square;
	
	return result;
}
