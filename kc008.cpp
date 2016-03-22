#include<cstdio>
long long int sumGlob,sum,tmp;
char sgn;
int main(void)
{
	while(scanf("%lld%c", &tmp, &sgn) != -1)
	{
		sum += tmp;
		sumGlob += tmp;

		if(sgn == '\n')
			printf("%lld\n", sum);

		if(tmp == 0)
			sum = 0;
	}
	printf("%lld\n", sumGlob);
	return 0;
}

