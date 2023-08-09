#include <iostream>

using namespace std;

int N, K;
int timeRecord[100004];
int visited[100004];
//int visitedTime[100004] = {987654321};

int run (int x, int t)
{
	int ret;
	
	if (visited[x]) return 0;
	if ( x<0 || x > 1000000 ) return 0;

//	if ( visitedTime[x] < t ) return 0;
//	else visitedTime[x] = t;
		
	visited[x]=1;
	
	//cout << x << " ";
	
	if (x==K) {
		timeRecord[t]++;
		//cout << "* ";
		visited[x]=0;
		return 1;
	} else {
		ret = run (x-1,t+1);
		
		ret = run (x+1, t+1);
		
		ret = run (2*x, t+1);
		
		visited[x]=0;
		return 0;
	}
	
	return 0;
}

int main()
{
	
	cin >> N >> K;
	
	run(N,0);
	
	for (int i=0;i<100000;i++){
		if (timeRecord[i]!=0)
		{
			cout << i << "\n";
			cout << timeRecord[i] << "\n";
			break;
		}
	}
	
	return 0;
}
