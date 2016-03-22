#include<cstdio>
#include<cstring>
long long unsigned int n, k;
int tests;
long long unsigned int newton(long long unsigned int n, long long unsigned int k)
{
	bool resultTab[1002],
		 kTab[1002];
	memset(resultTab, 0, sizeof(bool) * 1002);
	memset(kTab, 0, sizeof(bool) * 1002);

	long long unsigned int result = 1;
	if(n == k)
		return result;

	for(long long unsigned i = n - k + 1; i <= n; ++ i)
		resultTab[i] = 1;

	while(k > 1)
	{
		if(resultTab[k])
			resultTab[k] = 0;
		
		else
			kTab[k] = 1;

		-- k;
	}

	n = 1;
	k = 1;
	for(; n <= 1000; ++ n)
	{
		while(!kTab[k] && k <= 1000)
			++ k;

		while(!resultTab[n] && n <= 1000)
			++ n;

		if(n > 1000)
			break;

		result *= n;
		resultTab[n] = 0;

		if(k <= 1000 && result % k == 0)
		{
			result /= k;
			kTab[k] = 0;
		}
	}
	
	while(k <= 1000)
	{
		if(!kTab[k])
		{
			++k;
			continue;
		}
		result /= k;
		kTab[k] = 0;
		++ k;
	}

	return result;
}

int main()
{
	scanf("%d",&tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%llu %llu", &n, &k);
		printf("%llu\n", newton(n, k));
	}
	return 0;
}

