/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>
#include<vector>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

class BigInt
{
	private:
		char repr[10010];
		unsigned int size;

	public:
		inline BigInt(void);
		inline BigInt(const char * source);
		inline BigInt operator/(const unsigned int &div) const;
		inline unsigned int operator%(const unsigned int &mod) const;
		inline bool operator!(void) const;
};

unsigned int tests,
			 number,
			 MOD;
char power[10010];

inline static long long unsigned int fastPower(const long long unsigned int &n, BigInt pow);

int main(void)
{
	scanf("%u", &tests);
	for(unsigned int t = 0; t < tests; ++ t)
	{
		scanf("%u %s %u", &number, power, &MOD);
		printf("%llu\n", fastPower(number, BigInt(power)));
	}

	return 0;
}

inline static long long unsigned int fastPower(const long long unsigned int &n, BigInt pow)
{
	if(!pow)
		return 1;

	std::vector<bool> stack;
	long long unsigned int res = 1;
	while(!!pow)
	{
		stack.push_back(pow % 2);
		pow = pow / 2;
	}

	for(std::vector<bool>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++ it)
	{
		res = (res * res) % MOD;
		if(*it)
			res = (res * n) % MOD;
	}

	return res;
}

inline BigInt::BigInt(void)
{
	for(unsigned int r = 0; r < 10010; ++ r)
		this->repr[r] = 0;

	this->size = 0;
	return;
}

inline BigInt::BigInt(const char * source)
{
	this->size = 0;
	while(source[this->size])
	{
		this->repr[this->size] = source[this->size];
		++ this->size;
	}

	this->repr[this->size] = 0;
	return;
}

inline BigInt BigInt::operator/(const unsigned int &div) const
{
	BigInt num;
	unsigned int act = 0;
	for(unsigned int r = 0; r < this->size; ++ r)
	{
		act = act * 10 + this->repr[r] - '0';
		num.repr[num.size ++] = act / div + '0';
		act = act % div;
	}

	unsigned int nonzero = 0;
	while(num.repr[nonzero] == '0' && nonzero < num.size)
		++ nonzero;

	for(unsigned int r = nonzero; r < num.size; ++ r)
		std::swap(num.repr[r - nonzero], num.repr[r]);

	num.size -= nonzero;

	bool flag = false;
	for(unsigned int r = 0; !flag && r < num.size; ++ r)
		flag = num.repr[r] - '0';

	if(!flag)
	{
		num.size = 0;
		num.repr[0] = 0;
	}

	num.repr[num.size] = 0;
	return num;
}

inline unsigned int BigInt::operator%(const unsigned int &mod) const // only for mod == 2 ^^ 
{
	if(!this->size)
		return 0;

	return (this->repr[this->size - 1] - '0') % mod;
}

inline bool BigInt::operator!(void) const
{
	return !this->size || (this->size == 1 && this->repr[0] == '0');
}
