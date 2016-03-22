/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include <cstdio>


inline void erastotenes ( void );

int tests,
	start,
	dividers[10000012],
	end;

int main ( void )
{
	erastotenes ( );
	scanf("%d", &tests);
	for(int t = 0; t < tests; ++ t)
	{
		scanf("%d %d", &start, &end);
		printf("%d\n", dividers[end] - dividers[start-1]);
	}
	return 0;
}

inline void erastotenes ( void )
{
	for ( int i = 2; i * i <= 1000001; ++ i )
	{
		if ( dividers [ i ] )
			continue;
		
		dividers [ i ] = i;
		
		for ( int  j = i * i; j <= 1000001; j += i )
			if ( ! dividers [ j ] )
				dividers [ j ] = i;
	}

	for(int i = 2, res = 0; i <= 1000001; ++ i)
	{
		if(dividers[i] == i || !dividers[i])
			++ res;

		dividers[i] = res;
	}
	return;
}

