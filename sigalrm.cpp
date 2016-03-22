/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<signal.h>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

int main(void)
{
	kill(0, 14);
	return 0;
}

