/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char name[32];
std::vector<std::string> names;
std::string intToName[131072];
unsigned int count[131072],
			 counts,
			 sortMe[131072];

bool normalize(char *word);
bool compare(const unsigned int &a, const unsigned int &b);

int main(void)
{
	for(unsigned int s = 0; s < 131072; ++ s)
		sortMe[s] = s;

	while(scanf("%*d.%*s%s", name) != -1 && normalize(name))
		names.push_back(std::string(name));

	std::sort(names.begin(), names.end());
	intToName[0] = names[0];
	for(unsigned int n = 0; n < names.size(); ++ n)
	{
		if(n && names[n] != names[n - 1])
			intToName[++ counts] = names[n];

		++ count[counts];
	}

	std::sort(sortMe, sortMe + counts + 1, compare);
	for(unsigned int n = 0; n < counts + 1; ++ n)
		printf("%s %u\n", intToName[sortMe[n]].c_str(), count[sortMe[n]]);

	return 0;
}

bool normalize(char *word)
{
	for(unsigned int w = 0; word[w]; ++ w)
		if(word[w] >= 'a' && word[w] <= 'z')
			word[w] = word[w] - 'a' + 'A';

	return true;
}

bool compare(const unsigned int &a, const unsigned int &b)
{
	if(count[a] > count[b])
		return true;

	if(count[a] < count[b])
		return false;

	return a < b;
}
