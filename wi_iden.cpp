/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<algorithm>

int maxLen,
	varLen,
	newLen;
char variable[70000],
	 newVariable[70000];
bool first = true;

void reverse(char *word, int len);
void copy(char *f, char *t);
bool isLetter(char x);
bool isVowel(char x);
bool isDigit(char x);

int main(void)
{
	scanf("%d%s", &maxLen, variable);
	while(variable[varLen ++]);
	if(varLen <= maxLen)
	{
		puts(variable);
		return 0;
	}

	/* 1ST PHASE */
	reverse(variable, varLen);
	newLen = varLen;
	for(int n = 0, v = 0; v < varLen; ++ v)
	{
		if(newLen > maxLen && !isLetter(variable[v]) && !isDigit(variable[v]))
		{
			-- newLen;
			continue;
		}

		newVariable[n ++] = variable[v];
	}
	newVariable[newLen] = 0;

	copy(newVariable, variable);
	varLen = newLen;
	if(varLen <= maxLen)
	{
		reverse(variable, varLen);
		puts(variable);
		return 0;
	}

	/* 2ND PHASE */
	for(int n = 0, v = 0; v < varLen; ++ v)
	{
		if(newLen > maxLen && isDigit(variable[v]))
		{
			-- newLen;
			continue;
		}

		newVariable[n ++] = variable[v];
	}
	newVariable[newLen] = 0;

	copy(newVariable, variable);
	varLen = newLen;
	if(varLen <= maxLen)
	{
		reverse(variable, varLen);
		puts(variable);
		return 0;
	}

	/* 3RD PHASE */
	reverse(variable, newLen);
	for(int n = 0, v = 0; v < varLen; ++ v)
	{
		if(newLen > maxLen && isVowel(variable[v]))
		{
			if(!first)
			{
				-- newLen;
				continue;
			}

			first = false;
		}

		newVariable[n ++] = variable[v];
	}
	newVariable[newLen] = 0;

	copy(newVariable, variable);
	varLen = newLen;
	if(varLen <= maxLen)
	{
		puts(variable);
		return 0;
	}

	/* 4TH PHASE */
	for(int v = 0; v < maxLen - 1; ++ v)
		putchar(variable[v]);

	putchar(variable[varLen - 1]);
	return 0;
}

void reverse(char *word, int len)
{
	for(int l = 0; l < len / 2; ++ l)
		std::swap(word[l], word[len - 1 - l]);

	return;
}

void copy(char *f, char *t)
{
	for(int p = 0; f[p]; ++ p)
	{
		t[p] = f[p];
		t[p + 1] = 0;
	}

	return;
}

bool isLetter(char x)
{
	return x == '$' ||
		(x >= 'a' && x <= 'z') ||
		(x >= 'A' && x <= 'Z');
}

bool isVowel(char x)
{
	return x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y' ||
		   x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y';
}

bool isDigit(char x)
{
	return x <= '9' && x >= '0';
}
