#include<cstdio>
#include<algorithm>
int p,r;struct l{int a,b,c;bool operator<(const l&z)const{return a<z.a||(a==z.a&&(b<z.b||(b==z.b&&c<z.c)));}}P[1000];int main(){scanf("%d",&p);while(r<p){scanf("%d%d%d",&P[r].a,&P[r].b,&P[r].c);++r;}std::sort(P,P+p);r=0;while(r<p){printf("%d %d %d\n",P[r].a,P[r].b,P[r].c);++r;}}

