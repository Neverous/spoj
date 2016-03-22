/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>

char name[16],
	 surname[64],
	 date[16];

int nLength,
	sLength;

int check(void);

int main(void)
{
	while(scanf("%*s %s %*s %s %*s %*s %s ", name, surname, date) != -1)
	{
		nLength = strlen(name);
		sLength = strlen(surname);

		name[-- nLength] = 0;
		surname[-- sLength] = 0;
		printf("%d\n", check());
	}

	return 0;
}

int check(void)
{
	if(name[0] < 'A' || name[0] > 'Z')
		return 0;

	for(int n = 1; n < nLength; ++ n)
		if(name[n] < 'a' || name[n] > 'z')
			return 0;

	if(surname[0] < 'A' || surname[0] > 'Z')
		return 1;

	for(int s = 1; s < sLength; ++ s)
		if(surname[s] < 'a' || surname[s] > 'z')
			return 1;

	int year = 0,
		month = 0,
		day = 0;

	for(int d = 0; d < 4; ++ d)
		year = year * 10 + (date[d] - '0');

	for(int d = 5; d < 7; ++ d)
		month = month * 10 + (date[d] - '0');

	for(int d = 8; d < 10; ++ d)
		day = day * 10 + (date[d] - '0');

	if(year > 2000 || year < 1900 || month < 1 || month > 12 || day < 1 || day > 31)
		return 2;

	return 3;
}
