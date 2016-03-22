/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char action[16],
	 c;
int key,
	keyLen,
	sKey[10],
	modifier,
	pos;

int main(void)
{
	scanf("%s%d ", action, &key);
	modifier = (action[0] == 'S'?1:-1);
	if(!key)
	{
		keyLen = 1;
		sKey[0] = 0;
	}

	else
	{
		while(key)
		{
			sKey[keyLen ++] = key % 10;
			key /= 10;
		}

		for(int s = 0; s < keyLen / 2; ++ s)
			std::swap(sKey[s], sKey[keyLen - 1 - s]);
	}

	pos = 0;
	while((c = getchar()) != -1)
	{
		if(c < 'A' || c > 'Z')
			continue;

		putchar((26 + c - 'A' + sKey[pos] * modifier) % 26 + 'A');
		pos = (pos + 1) % keyLen;
	}

	return 0;
}

