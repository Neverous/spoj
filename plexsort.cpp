/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<string>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 order[256],
			 words;
char buffer[1024];
std::string word[131072];

static inline bool lexOperator(const std::string &A, const std::string &B);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		for(unsigned int o = 1; o < 256; ++ o)
			order[o] = 256;

		scanf("%s", buffer);
		for(unsigned int b = 0; buffer[b]; ++ b)
			order[(unsigned int)buffer[b]] = b + 1;

		scanf("%u", &words);
		for(unsigned int w = 0; w < words; ++ w)
		{
			scanf("%s", buffer);
			word[w] = buffer;
		}

		std::sort(word, word + words, lexOperator);
		for(unsigned int w = 0; w < words; ++ w)
			puts(word[w].c_str());

		puts("");
	}

	return 0;
}

static inline bool lexOperator(const std::string &A, const std::string &B)
{
	unsigned int p = 0;
	while(B[p] && A[p] && A[p] == B[p])
		++ p;

	return order[(unsigned int)B[p]] > order[(unsigned int)A[p]];
}
