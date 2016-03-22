/* Maciej Szeptuch 2009
XIV LO Wroc?aw
*/
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
/*
typedef long long int lld;
*/
char intA [ 10005 ],
	 intB [ 10005 ];

void substract ( char * a, char * b )
{
	bool swapped = 0,
		 started = 0;
	char c;

	int lengthA = strlen ( a ),
		lengthB = strlen ( b ),
		size = 0;

	if ( lengthA < lengthB || ( lengthA == lengthB && strcmp ( b, a ) > 0 ) )
	{
		swapped = true;
		for ( int i = 0 ; i < 10005; ++ i )
		{
			c = a [ i ];
			a [ i ] = b [ i ];
			b [ i ] = c;
		}
		size = lengthA;
		lengthA = lengthB;
		lengthB = size;
		size = 0;
	}

	char * zmienna = new char [ 10005 ];

	for ( int i = 0; i < 10005; ++ i )
		zmienna [ i ] = 0;

	for ( int i = 0; i < lengthA; ++ i )
		zmienna [ lengthA - i - 1 ] = a [ i ];

	for ( int i = lengthB - 1; i >= 0; -- i )
	{
		if ( zmienna [ lengthB - i - 1 ] < b [ i ] )
		{
			zmienna [ lengthB - i ] -= 1;
			zmienna [ lengthB - i - 1 ] += 10;
		}
		zmienna [ lengthB - i - 1 ] -= b [ i ] - '0';
	}

	for ( int i = lengthA - 1; i >= 0; -- i )
	{
		if ( zmienna [ lengthA - i - 1 ] < '0' )
		{
			zmienna [ lengthA - i ] -= 1;
			zmienna [ lengthA - i - 1 ] += 10;
		}
	}
	size = strlen ( zmienna );

	if ( swapped )
		a [ 0 ] = '-';

	for ( int i = 0,j = ( swapped ) ? 1 : 0; i < size ; ++ i )
	{
		if ( ! started && zmienna [ size - 1 - i ] > '0' )
			started = true;

		if ( ! started && zmienna [ size - 1 - i ] == '0' )
			continue;

		a [ j ] = zmienna [ size - 1 - i ];
		a [ j + 1 ] = 0;
		j++;
	}
	if ( ! started )
	{
		a [ 0 ] = '0';
		a [ 1 ] = 0;
	}
}

int main ( void )
{
	while ( scanf ( "%s %s", intA, intB ) != -1 )
	{
		substract ( intA, intB );
		printf ( "%s\n", intA );
    }
    #ifdef WIN$HIT
    system ( "pause" );
    #endif
    return 0;
}

