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

const int BUFFER = 4096;
int p = BUFFER - 1;
char buffer[BUFFER];

std::string name;
int people,
	jump,
	points,
	note[8];
std::pair<int, std::string> result[64];

int getInt(void);
std::string getString(void);
bool comp(const std::pair<int, std::string> &A, const std::pair<int, std::string> &B);

int main(void)
{
	people = getInt();
	for(int P = 0; P < people; ++ P)
	{
		name = getString();
		jump = getInt();
		for(int n = 0; n < 5; ++ n)
			note[n] = getInt();

		std::sort(note, note + 5);
		points = (note[1] + note[2] + note[3]) * 10 + 6000 + (jump - 1200) * 18;
		points = MAX(points, 0);
		//printf("%s %d %d %d %d %d %d => %d\n", name.c_str(), jump, note[0], note[1], note[2], note[3], note[4], points);
		result[P] = std::pair<int, std::string>(points, name);
	}

	std::sort(result, result + people, comp);
	for(int P = 0; P < people; ++ P)
		printf("%d. %s %d.%d\n", P + 1, result[P].second.c_str(), result[P].first / 100, (result[P].first % 100) / 10);

	return 0;
}

int getInt(void)
{
	int number = 0;
	while((buffer[p] < '0' || buffer[p] > '9') && ++ p)
		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while(buffer[p] == '.' || (buffer[p] >= '0' && buffer[p] <= '9'))
	{
		if(buffer[p] == '.')
		{
			++ p;
			continue;
		}

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

std::string getString(void)
{
	std::string res;
	while((buffer[p] == ' ' || buffer[p] == '\t' || buffer[p] == '\n' || buffer[p] == '\r') && ++ p)
		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}

	while((buffer[p] != ' ' && buffer[p] != '\t' && buffer[p] != '\n' && buffer[p] != '\r'))
	{
		res += buffer[p];
		++ p;

		if(p == BUFFER)
		{
			fread(buffer, sizeof(char), BUFFER, stdin);
			p = 0;
		}
	}

	return res;
}

bool comp(const std::pair<int, std::string> &A, const std::pair<int, std::string> &B)
{
	if(A.first > B.first)
		return true;

	if(A.first < B.first)
		return false;

	return A.second < B.second;
}
