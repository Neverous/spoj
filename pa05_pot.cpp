#include<cstdio>
int a,b,tests;

int fastPower(int a, int power)
{
    if(power==0)
        return 1;
    
    if(power%2)
        return (a * fastPower(a, power-1))%10;
    
    int half = fastPower(a, power/2);
    return (half*half)%10;
}
int main(void)
{
	scanf("%d ", &tests);
	for(int i=0;i<tests;i++)
	{
		scanf("%d %d", &a, &b);
		a %= 10;
		printf("%d\n", fastPower(a,b)%10);
	}
	return 0;
}

