/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include <stdio.h>

int tests,
	age,
	size,
	weight,
	bmi,
	t;

char sex [ 5 ];
int tab [ 7 ] [ 30 ] [ 2 ];

int main ( int args, char ** argv )
{
	tab [ 0 ] [ 'M' - 'A' ] [ 0 ] = 152; tab [ 0 ] [ 'M' - 'A' ] [ 1 ] = 261;
	tab [ 1 ] [ 'M' - 'A' ] [ 0 ] = 157; tab [ 1 ] [ 'M' - 'A' ] [ 1 ] = 264;
	tab [ 2 ] [ 'M' - 'A' ] [ 0 ] = 163; tab [ 2 ] [ 'M' - 'A' ] [ 1 ] = 268;
	tab [ 3 ] [ 'M' - 'A' ] [ 0 ] = 169; tab [ 3 ] [ 'M' - 'A' ] [ 1 ] = 273;
	tab [ 4 ] [ 'M' - 'A' ] [ 0 ] = 175; tab [ 4 ] [ 'M' - 'A' ] [ 1 ] = 278;
	tab [ 5 ] [ 'M' - 'A' ] [ 0 ] = 179; tab [ 5 ] [ 'M' - 'A' ] [ 1 ] = 282;
	tab [ 6 ] [ 'M' - 'A' ] [ 0 ] = 183; tab [ 6 ] [ 'M' - 'A' ] [ 1 ] = 286;
	tab [ 0 ] [ 'W' - 'A' ] [ 0 ] = 154; tab [ 0 ] [ 'W' - 'A' ] [ 1 ] = 254;
	tab [ 1 ] [ 'W' - 'A' ] [ 0 ] = 160; tab [ 1 ] [ 'W' - 'A' ] [ 1 ] = 263;
	tab [ 2 ] [ 'W' - 'A' ] [ 0 ] = 166; tab [ 2 ] [ 'W' - 'A' ] [ 1 ] = 268;
	tab [ 3 ] [ 'W' - 'A' ] [ 0 ] = 169; tab [ 3 ] [ 'W' - 'A' ] [ 1 ] = 272;
	tab [ 4 ] [ 'W' - 'A' ] [ 0 ] = 172; tab [ 4 ] [ 'W' - 'A' ] [ 1 ] = 273;
	tab [ 5 ] [ 'W' - 'A' ] [ 0 ] = 174; tab [ 5 ] [ 'W' - 'A' ] [ 1 ] = 274;
	tab [ 6 ] [ 'W' - 'A' ] [ 0 ] = 175; tab [ 6 ] [ 'W' - 'A' ] [ 1 ] = 274;
	scanf ( "%d", & tests );
	for ( t = 0; t < tests; ++ t )
	{
		scanf ( "%s%d%d%d", sex, & age, & size, & weight );
		bmi = weight * 1000000 / ( size * size );
		if ( bmi % 10 > 5 )
			bmi += 10;

		else if ( bmi == 5 && ( bmi / 10 ) % 10 )
			bmi += 10;

		bmi /= 10;
		printf ( "%0.1lf %s\n", ( double ) bmi / 10, ( bmi < tab [ age - 13 ] [ sex [ 0 ] - 'A' ] [ 0 ] || bmi > tab [ age - 13 ] [ sex [ 0 ] - 'A' ] [ 1 ] ) ? "WARNING" : "" );
	}

	return 0;
}
