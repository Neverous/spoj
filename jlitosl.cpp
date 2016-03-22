/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<string>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests;
long long unsigned int number;
std::string numberToWord(long long unsigned int num);
std::string suffix[5] = {"", "tys. ", "mln. ", "mld. ", "bln. "},
			units[10] = {"", "jeden ", "dwa ", "trzy ", "cztery ", "piec ",
						 "szesc ", "siedem ", "osiem ", "dziewiec "},
			tens[10] = {"", "dziesiec ", "dwadziescia ", "trzydziesci ",
						"czterdziesci ", "piecdziesiat ", "szescdziesiat ",
						"siedemdziesiat ", "osiemdziesiat ", "dziewiecdziesiat "},
			hundreds[10] = {"", "sto ", "dwiescie ", "trzysta ", "czterysta ",
							"piecset ", "szescset ", "siedemset ", "osiemset ",
							"dziewiecset "};

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%llu", &number);
		printf("%s\n", numberToWord(number).c_str());
	}

	return 0;
}

std::string numberToWord(long long unsigned int num)
{
	if(num >= 1000)
	{
		std::string word;
		for(int p = 0; num; ++ p)
		{
			if(num % 1000)
				word = numberToWord(num % 1000) + suffix[p] + word;

			num /= 1000;
		}

		return word;
	}

	switch(num % 100)
	{
		case 11: return hundreds[num / 100] + "jedenascie ";
		case 12: return hundreds[num / 100] + "dwanascie ";
		case 13: return hundreds[num / 100] + "trzynascie ";
		case 14: return hundreds[num / 100] + "czternascie ";
		case 15: return hundreds[num / 100] + "pietnascie ";
		case 16: return hundreds[num / 100] + "szesnascie ";
		case 17: return hundreds[num / 100] + "siedemnascie ";
		case 18: return hundreds[num / 100] + "osiemnascie ";
		case 19: return hundreds[num / 100] + "dziewietnascie ";
	}

	return hundreds[num / 100] + tens[(num / 10) % 10] + units[num % 10];
}
