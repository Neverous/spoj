<?php
/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
$tab = array (
	13 => array (
		'M' => array ( 152, 261 ),
		'W' => array ( 154, 254 ),
	),
	14 => array (
		'M' => array ( 157, 264 ),
		'W' => array ( 160, 263 ),
	),
	15 => array (
		'M' => array ( 163, 268 ),
		'W' => array ( 166, 268 ),
	),
	16 => array (
		'M' => array ( 169, 273 ),
		'W' => array ( 169, 272 ),
	),
	17 => array (
		'M' => array ( 175, 278 ),
		'W' => array ( 172, 273 ),
	),
	18 => array (
		'M' => array ( 179, 282 ),
		'W' => array ( 174, 274 ),
	),
	19 => array (
		'M' => array ( 183, 186 ),
		'W' => array ( 175, 274 ),
	),
);
$stdout = '';
$stdin = file_get_contents('php://stdin');
$stdin = explode ( "\n", $stdin );
$tests = (int) $stdin [ 0 ];
for ( $t = 0; $t < $tests; ++$t )
{
	$data = explode ( ' ', $stdin [ $t + 1 ] );
	$sex = $data [ 0 ];
	$age = (int) $data [ 1 ];
	$size = (int) $data [ 2 ];
	$weight = (int) $data [ 3 ];
	$bmi = (int) ( $weight * 1000000 / ( $size * $size ) );

	if ( $bmi == 5 && ( $bmi / 10 ) % 10 )
		$bmi += 10;

	$bmi = round ( $bmi / 10 );
	$stdout .= sprintf ( "%0.1f%s\n", $bmi * 0.1, ( $bmi < $tab [ $age ] [ $sex ] [ 0 ] || $bmi > $tab [ $age ] [ $sex ] [ 1 ] ) ? " WARNING" : "" );
}
echo $stdout
?>
