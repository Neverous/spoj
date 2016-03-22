/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

unsigned int tests,
			 verts,
			 edges,
			 from,
			 to,
			 cost,
			 shortest[1 << 14];
std::vector<std::pair<unsigned int, unsigned int> > graph[1 << 14];

inline unsigned int dijkstra(const unsigned int &start, const unsigned int &end);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %u", &verts, &edges);
		for(unsigned int v = 0; v < verts; ++ v)
		{
			graph[v].clear();
			shortest[v] = 1 << 30;
		}

		for(unsigned int e = 0; e < edges; ++ e)
		{
			scanf("%u %u %u", &from, &to, &cost);
			-- from;
			-- to;
			graph[from].push_back(std::make_pair(cost, to));
		}

		for(unsigned int v = 0; v < verts; ++ v)
			std::sort(graph[v].begin(), graph[v].end());

		scanf("%u %u", &from, &to);
		to = dijkstra(-- from, -- to);
		if(to == 1 << 30)
			printf("NIE\n");

		else
			printf("%u\n", to);
	}
	return 0;
}

inline unsigned int dijkstra(const unsigned int &start, const unsigned int &end)
{
	std::pair<int, unsigned int> act;
	std::priority_queue<std::pair<int, unsigned int> > que;
	que.push(std::make_pair(0, start));
	while(!que.empty() && shortest[end] == 1 << 30)
	{
		act = que.top();
		que.pop();
		act.first = -act.first;
		if(shortest[act.second] <= (unsigned int)act.first)
			continue;

		shortest[act.second] = act.first;
		for(unsigned int n = 0; n < graph[act.second].size(); ++ n)
			if(shortest[graph[act.second][n].second] > act.first + graph[act.second][n].first)
				que.push(std::make_pair(-act.first - graph[act.second][n].first, graph[act.second][n].second));
	}

	return shortest[end];
}
