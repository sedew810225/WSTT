//최단거리 알고리즘은 어떤게 있는가?
// BSF 를 사용할때 문제에서 적합한 자료구조를 선택할 수 있는가? 

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N,K;
queue <pair<int,int>> q;
stack <int> s;

bool visited[100004];
int parent[100004];
int run()
{
	int x,time;
	int nx;
	
	int minTime=987654321;
	int minTimeCnt=0;
	
	q.push(make_pair(N,0));
	visited[N] = true;
	
	while (!q.empty())
	{
		x = q.front().first;
		time = q.front().second;	
		q.pop();
		//visited[x] = true;	// it can have multiple path 
							
		if (x==K) {
			if ( time < minTime ){
				minTime = time;
				minTimeCnt = 1;
				break;
			}
			else if ( time == minTime ){
				minTimeCnt++;
			}
			continue;	
		}
		
		nx = x-1;
		if (nx>=0 && (visited[nx]==false)){
			q.push(make_pair(nx,time+1));
			parent[nx]=x;	
			visited[nx]=true; // prevent multiple path
		} 
		nx = x+1;
		if (nx<=100000 && (visited[nx]==false)){
			q.push(make_pair(nx,time+1));
			parent[nx]=x;
			visited[nx]=true;	 // prevent multiple path
		} 
		nx = x*2;
		if (nx<=100000 && (visited[nx]==false)){
			q.push(make_pair(x*2,time+1));
			parent[nx]=x;
			visited[nx]=true;	 // prevent multiple path
		} 
		
	}	
	
	cout << minTime << "\n";
	
	int st = K;
	while ( st != N)
	{
		s.push(st);
		st = parent[st];	
	}
	s.push(N);
	while (!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	
	return 0;
}

int main()
{
	cin >> N >> K;
	
	run();	
	
	return 0;
}
