#include<cstdio>
int result;
char sgn;
int main(void)
{
	while(scanf("%c", &sgn)!=-1)
		if(sgn == '\n')
			++ result;

	if(sgn != '\n')
		++ result;

	printf("%d\n", result);
	return 0;
}

