//최단거리 알고리즘은 어떤게 있는가?
// BSF 를 사용할때 문제에서 적합한 자료구조를 선택할 수 있는가? 

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int N,K;
queue <pair<int,int>> q;
int visited[500004];

int run()
{
	int x,time;
	int nx, nK;
	
	int minTime=987654321;
	int minTimeCnt=0;
	
	memset(visited,-1,sizeof(visited));
	
	q.push(make_pair(N,0));
	visited[x]=0;
	
	while (!q.empty())
	{
		x = q.front().first;
		time = q.front().second;	
		q.pop();
		
		if (x <0 || x>500000) continue;

		visited[x]= time;
		
		nK = K + time*(time+1)/2;				

		if (nK > 500000){
			break;	
		}  				
		
		if (x==nK) {
			if ( time < minTime ){
				minTime = time;
				minTimeCnt = 1;
				break;
			}
			continue;	
		}
		
		nx = x-1;
			q.push(make_pair(nx,time+1));
		
		nx = x+1;
			q.push(make_pair(nx,time+1));
		
		nx = x*2;
			q.push(make_pair(x*2,time+1)); 		
	}	
	
	if (minTimeCnt==0) cout << -1 <<"\n";
	else cout << minTime << "\n";
	
	return 0;
}

int main()
{
	cin >> N >> K;
	
	run();	
	
	return 0;
}
