#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int tests,x,y,points;
pair<pair<int,int>, int> point[1001];
char name[1001][12];
bool cmp(const pair<pair<int,int>, int>& A,const pair<pair<int,int>, int>& B)
{
	return A.first.first * A.first.first + A.first.second * A.first.second < B.first.first * B.first.first + B.first.second * B.first.second;
}
		
int main(void)
{
	scanf("%d", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d", &points);
		for(int j=0;j<points;j++)
		{
			scanf("%s %d %d", name[j], &x, &y);
			point[j] = make_pair(make_pair(x,y),j);
		}
		sort(point,point +points, cmp);
		for(int j=0;j<points;j++)
			printf("%s %d %d\n", name[point[j].second], point[j].first.first, point[j].first.second);
	}
	return 0;
}

