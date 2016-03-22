/* 
   Laboratorium Praktyki Programowania  
*/

#include <iostream>
#include <cmath>

using namespace std;

#define T_SIZE 1000


int average(int T[], int n);
void read_data(int T[], int n);

int main(){
  int t,n; 
  int T[T_SIZE];

  cin >> t; /* wczytaj liczbę testów */
  while(t){ 
    cin >> n;
    read_data(T,n);
    cout << average(T,n) << endl;

    t--; 
  } 
  return 0;
}

/* ........................
 Tu napisz potrzebne funkcje
 */

int average(int T[], int n)
{
	int result=1000000;
	double sum = 0;
	for(int i=0;i<n;i++)
		sum += T[i];
		
	sum /= n;
	for(int i=0;i<n;i++)
		if(abs((double)T[i]-sum)<abs((double)result-sum))
			result = T[i];
			
	return result;
}
void read_data(int T[], int n)
{
	for(int i=0;i<n;i++)
		cin>>T[i];
}

