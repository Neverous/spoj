/* 2011
 * Maciej Szeptuch
 * II UWr
 */
#include<cstdio>
#include<vector>
#include<algorithm>

int xs, ys,
	xe, ye,
	row[32768],
	result;
std::vector<std::pair<std::pair<int, bool>, std::pair<int, int> > > lines;

int main(void)
{
	scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
	lines.push_back(std::make_pair(std::make_pair(xs, true), std::make_pair(ys, ye)));
	lines.push_back(std::make_pair(std::make_pair(xe, false), std::make_pair(ys, ye)));

	scanf("%d %d %d %d", &xs, &ys, &xe, &ye);
	lines.push_back(std::make_pair(std::make_pair(xs, true), std::make_pair(ys, ye)));
	lines.push_back(std::make_pair(std::make_pair(xe, false), std::make_pair(ys, ye)));

	std::sort(lines.begin(), lines.end());
	for(unsigned int l = 0, count; l + 1 < lines.size(); ++ l)
	{
		count = 0;
		for(int y = 0; y < 32768; ++ y)
			count += !!(row[y] += (y >= lines[l].second.first && y < lines[l].second.second)*(lines[l].first.second?1:-1));

		result += count * (lines[l + 1].first.first - lines[l].first.first);
	}

	printf("%d\n", result);
	return 0;
}
