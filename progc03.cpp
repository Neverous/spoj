/* 2010
 * Maciej Szeptuch
 * XIV LO Wrocław
 */
#include<cstdio>
#include<cstring>
#include<list>
//#define DEBUG(args...) fprintf(stderr, args)
#define DEBUG(args...)
char action[16];
unsigned int _who,
			 _state,
			 _args,
			 argv[4];
bool stackExists[10],
	 queueExists[10];
std::list<unsigned int> stack[10],
						queue[10];

inline void createStack(const unsigned int &id);
inline void removeStack(const unsigned int &id);
inline void printStack(const unsigned int &id);
inline void uploadStack(const unsigned int &id, const unsigned int value);
inline unsigned int downloadStack(const unsigned int &id);

inline void createQueue(const unsigned int &id);
inline void removeQueue(const unsigned int &id);
inline void printQueue(const unsigned int &id);
inline void uploadQueue(const unsigned int &id, const unsigned int value);
inline unsigned int downloadQueue(const unsigned int &id);

inline void stackToStack(const unsigned int &s1, const unsigned int &s2);
inline void stackToQueue(const unsigned int &s, const unsigned int &q);
inline void queueToQueue(const unsigned int &q1, const unsigned int &q2);
inline void queueToStack(const unsigned int &q, const unsigned int &s);

int main(void)
{
	while(scanf("%s", action) != -1)
	{
		_who = _state = _args = 0;
		if(!strcmp(action, "new_s")){_who = 1; _state = 1; _args = 1;}
		else if(!strcmp(action, "new_q")){_who = 2; _state = 1; _args = 1;}
		else if(!strcmp(action, "delete_s")){_who = 1; _state = 2; _args = 1;}
		else if(!strcmp(action, "delete_q")){_who = 2; _state = 2; _args = 1;}
		else if(!strcmp(action, "print_s")){_who = 1; _state = 3; _args = 1;}
		else if(!strcmp(action, "print_q")){_who = 2; _state = 3; _args = 1;}
		else if(!strcmp(action, "push")){_who = 1; _state = 4; _args = 2;}
		else if(!strcmp(action, "pop")){_who = 1; _state = 5; _args = 1;}
		else if(!strcmp(action, "enqueue")){_who = 2; _state = 4; _args = 2;}
		else if(!strcmp(action, "dequeue")){_who = 2; _state = 5; _args = 1;}
		else if(!strcmp(action, "stack->stack")){_who = 3; _state = 6; _args = 2;}
		else if(!strcmp(action, "stack->queue")){_who = 3; _state = 7; _args = 2;}
		else if(!strcmp(action, "queue->stack")){_who = 3; _state = 8; _args = 2;}
		else if(!strcmp(action, "queue->queue")){_who = 3; _state = 9; _args = 2;}

		try
		{
			for(unsigned int a = 0; a < _args; ++ a)
				scanf("%u", &argv[a]);

			if(!_who || !_state || !_args)
				throw "unknown command";

			switch(_state)
			{
				case 1:
					if(_who == 1) createStack(argv[0]);
					else createQueue(argv[0]);
					break;

				case 2:
					if(_who == 1) removeStack(argv[0]);
					else removeQueue(argv[0]);
					break;

				case 3:
					if(_who == 1) printStack(argv[0]);
					else printQueue(argv[0]);
					break;

				case 4:
					if(_who == 1) uploadStack(argv[0], argv[1]);
					else uploadQueue(argv[0], argv[1]);
					break;

				case 5:
					if(_who == 1) downloadStack(argv[0]);
					else downloadQueue(argv[0]);
					break;

				case 6:
					stackToStack(argv[0], argv[1]);
					break;

				case 7:
					stackToQueue(argv[0], argv[1]);
					break;

				case 8:
					queueToStack(argv[0], argv[1]);
					break;

				case 9:
					queueToQueue(argv[0], argv[1]);
					break;
			}

		}
		catch(const char* description)
		{
			printf("error: %s\n", description);
		}

	}

	return 0;
}

inline void createStack(const unsigned int &id)
{
	if(stackExists[id])
		throw "stack already exists";

	stackExists[id] = true;
	stack[id].clear();
}

inline void removeStack(const unsigned int &id)
{
	if(!stackExists[id])
		throw "stack doesnt exist";

	stackExists[id] = false;
}

inline void printStack(const unsigned int &id)
{
	if(!stackExists[id])
		throw "stack doesnt exist";

	if(stack[id].empty())
	{
		puts("empty");
		return;
	}

	for(std::list<unsigned int>::iterator s = stack[id].begin(); s != stack[id].end(); ++ s)
		printf("%u ", *s);

	puts("");
}

inline void uploadStack(const unsigned int &id, const unsigned int value)
{
	if(!stackExists[id])
		throw "stack doesnt exist";

	if(stack[id].size() == 10)
		throw "stack is full";

	stack[id].push_back(value);
}

inline unsigned int downloadStack(const unsigned int &id)
{
	if(!stackExists[id])
		throw "stack doesnt exist";

	if(stack[id].empty())
		throw "stack is empty";

	unsigned int value = stack[id].back();
	stack[id].pop_back();
	return value;
}

inline void createQueue(const unsigned int &id)
{
	if(queueExists[id])
		throw "queue already exists";

	queueExists[id] = true;
	queue[id].clear();
}

inline void removeQueue(const unsigned int &id)
{
	if(!queueExists[id])
		throw "queue doesnt exist";

	queueExists[id] = false;
}

inline void printQueue(const unsigned int &id)
{
	if(!queueExists[id])
		throw "queue doesnt exist";

	if(queue[id].empty())
	{
		puts("empty");
		return;
	}

	for(std::list<unsigned int>::reverse_iterator s = queue[id].rbegin(); s != queue[id].rend(); ++ s)
		printf("%u ", *s);

	puts("");
}

inline void uploadQueue(const unsigned int &id, const unsigned int value)
{
	if(!queueExists[id])
		throw "queue doesnt exist";

	if(queue[id].size() == 10)
		throw "queue is full";

	queue[id].push_back(value);
}

inline unsigned int downloadQueue(const unsigned int &id)
{
	if(!queueExists[id])
		throw "queue doesnt exist";

	if(queue[id].empty())
		throw "queue is empty";

	unsigned int value = queue[id].front();
	queue[id].pop_front();
	return value;
}

inline void stackToStack(const unsigned int &s1, const unsigned int &s2)
{
	if(!stackExists[s1] || !stackExists[s2] || stack[s1].empty())
		throw "wrong command";

	if(s1 != s2 && stack[s2].size() == 10)
		throw "wrong command";

	uploadStack(s2, downloadStack(s1));
}

inline void stackToQueue(const unsigned int &s, const unsigned int &q)
{
	if(!stackExists[s] || !queueExists[q] || stack[s].empty() || queue[q].size() == 10)
		throw "wrong command";

	uploadQueue(q, downloadStack(s));
}

inline void queueToQueue(const unsigned int &q1, const unsigned int &q2)
{
	if(!queueExists[q1] || !queueExists[q2] || queue[q1].empty())
		throw "wrong command";

	if(q1 != q2 && queue[q2].size() == 10)
		throw "wrong command";

	uploadQueue(q2, downloadQueue(q1));
}

inline void queueToStack(const unsigned int &q, const unsigned int &s)
{
	if(!queueExists[q] || !stackExists[s] || queue[q].empty() || stack[s].size() == 10)
		throw "wrong command";

	uploadStack(s, downloadQueue(q));
}
