/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#define MAX(a, b) ((a) > (b)?(a):(b))
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

std::string name;
char buffer[256];
int people;
std::pair<long double, std::string> result[64];
long double jump,
			note[8],
			points;

bool comp(const std::pair<long double, std::string> &A, const std::pair<long double, std::string> &B);

int main(void)
{
	scanf("%d", &people);
	for(int P = 0; P < people; ++ P)
	{
		scanf("%s %Lf", buffer, &jump);
		name = std::string(buffer);
		for(int n = 0; n < 5; ++ n)
			scanf("%Lf", &note[n]);

		std::sort(note, note + 5);
		points = note[1] + note[2] + note[3] + 60 + (jump - 120) * 1.8;
		points = MAX(points, 0);
		//printf("%s %d %d %d %d %d %d => %d\n", name.c_str(), jump, note[0], note[1], note[2], note[3], note[4], points);
		result[P] = std::pair<long double, std::string>(points, name);
	}

	std::sort(result, result + people, comp);
	for(int P = 0; P < people; ++ P)
		printf("%d. %s %.1Lf\n", P + 1, result[P].second.c_str(), result[P].first);

	return 0;
}

bool comp(const std::pair<long double, std::string> &A, const std::pair<long double, std::string> &B)
{
	if(A.first - B.first > 0.01)
		return true;

	if(B.first - A.first > 0.01)
		return false;

	return A.second < B.second;
}
