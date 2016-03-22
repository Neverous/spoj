#include <cstdio>

int tests,
	a,
	b;

int main ( void )
{
	scanf ( "%d", & tests );
	for ( int t = 0; t < tests; ++ t )
	{
		scanf ( "%d %d", & a, & b );
		printf ( "%d\n", ( 2 * a * b ) / ( a + b ) );
	}
	return 0;
}

