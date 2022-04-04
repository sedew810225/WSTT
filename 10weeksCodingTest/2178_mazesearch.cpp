//shorted path
//DFS ? 
//BFS ? > BFS
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int N, M;
int a[104][104];
int d[104][104];

queue< pair<int,int> > q;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void makeBFS(int sx, int sy)
{
	int x,y;
	int nx,ny;
	
	d[sx][sy] = 1;
	q.push({sx,sy});
	
	while (q.size())  // remember
	{
		tie(x,y) = q.front();
		q.pop();
		
		for (int i=0;i<4;i++)
		{
			
			nx = x + dx[i];
			ny = y + dy[i];
			
			if (nx<0 || ny<0 || nx > N || ny > M ) continue;
			if ( a[nx][ny]==1 && d[nx][ny]==0){
				d[nx][ny] = d[x][y]+1;
				q.push({nx,ny});
			}
		}	
	}
	
	return ;
}

int main()
{
	cin >> N >> M;
	
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			scanf("%1d",&a[i][j]);	// remember
		}
	}

	makeBFS(0,0);
	
	cout << d[N-1][M-1] << "\n";
	
	return 0;
}
