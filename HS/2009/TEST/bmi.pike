/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
import Stdio;

int main ()
{
int tests,
	age,
	size,
	weight,
	bmi,
	t;

string sex;
array(array(array(int))) tab;
tab = ({
({ ({ 152, 261 }), ({ 154, 254 }) }),
({ ({ 157, 264 }), ({ 160, 263 }) }),
({ ({ 163, 268 }), ({ 166, 268 }) }),
({ ({ 169, 273 }), ({ 169, 272 }) }),
({ ({ 175, 278 }), ({ 172, 273 }) }),
({ ({ 179, 282 }), ({ 174, 274 }) }),
({ ({ 183, 286 }), ({ 175, 274 }) }),
});
	sscanf ( stdin->gets(), "%d", tests );
	for ( t = 0; t < tests; ++ t )
	{
		sscanf ( stdin->gets(), "%s%d%d%d", sex, age, size, weight );
		bmi = weight * 1000000 / ( size * size );
		if ( bmi % 10 > 5 )
			bmi += 10;

		else if ( bmi == 5 && ( bmi / 10 ) % 10 )
			bmi += 10;

		bmi /= 10;
		string warning = "";
		if ( bmi < tab[age - 13][sex[0]=='M'?0:1][0] || bmi > tab [ age - 13 ] [ sex [ 0 ]=='M'?0:1] [ 1 ] )
			warning = " WARNING";

		write ( "%.1f", 0.1 * bmi );
		write ( "%s\n", warning );
	}

	return 0;
}
