/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#define PASSTIME(minutes) minute += minutes; hour = (hour + minute / 60) % 24; minute %= 60;

int hour,
	minute,
	brk;

int main(void)
{
	scanf("%d:%d", &hour, &minute);
	printf("%02d:%02d,", hour, minute);
	PASSTIME(45);
	printf("%02d:%02d", hour, minute);
	while(scanf("%d", &brk) != -1)
	{
		PASSTIME(brk);
		printf(",%02d:%02d", hour, minute);
		PASSTIME(45);
		printf(",%02d:%02d", hour, minute);
	}

	puts("");
	return 0;
}

