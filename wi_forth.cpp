/* 2011
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
#include<list>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)

char buffer[1024];
long long int number;
std::list<int> stack;

int stackPop(void);
void stackPush(int value);
void stackDup(void);
void stackDiv(void);
void stackSub(void);
void stackRot(void);

int main(void)
{
	while(scanf("%s", buffer) != -1)
	{
		try
		{
			for(unsigned int b = 0; buffer[b]; ++ b)
				if(buffer[b] >= 'A' && buffer[b] <= 'Z')
					buffer[b] -= 'A' - 'a';

			if(!strcmp(buffer, "+")) stackPush(stackPop() + stackPop());
			else if(!strcmp(buffer, "-")) stackSub();
			else if(!strcmp(buffer, "*")) stackPush(stackPop() * stackPop());
			else if(!strcmp(buffer, "/")) stackDiv();
			else if(!strcmp(buffer, ".")) printf("%d ", stackPop());
			else if(!strcmp(buffer, "dup")) stackDup();
			else if(!strcmp(buffer, "drop")) stackPop();
			else if(!strcmp(buffer, "rot")) stackRot();
			else
			{
				for(unsigned int b = 0; buffer[b]; ++ b)
					if(buffer[b] < '0' || buffer[b] > '9')
						throw "Unknown operator";

				sscanf(buffer, "%lld", &number);
				if(number > ((long long int)1 << 31) - 1)
					throw "Too big input";

				stackPush((int)number);
			}
		}
		catch(const char *description)
		{
			printf("ERR");
			//puts(description);
			return 0;
		}
	}

	return 0;
}

int stackPop(void)
{
	if(stack.empty())
		throw "Stack is empty";

	int temp = stack.back();
	stack.pop_back();
	return temp;
}

void stackPush(int value)
{
	if(stack.size() == 1000)
		throw "Stack is full";

	stack.push_back(value);
}

void stackDiv(void)
{
	int a = stackPop(),
		b = stackPop();

	if(!a)
		throw "Floating point exception";

	stackPush(b / a);
}

void stackDup(void)
{
	if(stack.size() == 1000)
		throw "Stack is full";

	if(stack.empty())
		throw "Stack is empty";

	stackPush(stack.back());
}

void stackRot(void)
{
	if(stack.empty())
		throw "Stack is empty";

	if(stack.size() == 1)
		return;

	if(stack.size() == 2)
	{
		int a = stackPop(),
			b = stackPop();

		stackPush(a);
		stackPush(b);
		return;
	}

	if(stack.size() >= 3)
	{
		int a = stackPop(),
			b = stackPop(),
			c = stackPop();

		stackPush(b);
		stackPush(a);
		stackPush(c);
	}
}

void stackSub(void)
{
	int a = stackPop(),
		b = stackPop();

	stackPush(b - a);
}
