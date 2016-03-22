<?php
/* 2009
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
$stdout = '';
$stdin = file_get_contents('php://stdin');
$stdin = explode("\n", $stdin);
$tests = (int)$stdin[0];
for($t = 0; $t < $tests; ++$t)
{
	$data = explode(' ', $stdin [ $t + 1 ]);
	$stdout .= gmp_strval(gmp_mul($data[0], $data[1])) . "\n";
}
echo $stdout
?>
