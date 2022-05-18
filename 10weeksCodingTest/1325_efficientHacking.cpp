#include <iostream>
#include <vector>
#include <stack>
#include <string.h>

using namespace std;

vector<int> m[10004];
int cnt[10004];
int visited[10004];

stack<int> st;

void checkHack(int num, int start)
{
	int next;
	
	visited[num] = 1;	
	cnt[start] ++;
	
	for (auto a : m[num])
	{
		if (visited[a]==0) checkHack(a, start);		// use correct data structure, stack is useless
	}
	
	return;
}

int main()
{
	int N, M;
	int a,b;
	int max=0;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	
	for (int i=0;i<M;i++)
	{
		cin >> a >> b;
		m[b].push_back(a);		
	}

	for (int i=1;i<=N;i++){
		if ( m[i].size()==0 ) continue;
		cnt[i] = 0;
		memset(visited, 0, sizeof(visited));
		checkHack(i, i);
		if ( cnt[i] > max )
		{
			max = cnt[i];	
		}
	}
	
	for (int i=1;i<=N;i++){
		if ( cnt[i] == max ) cout << i << " ";
	}
	
	return 0;
}
