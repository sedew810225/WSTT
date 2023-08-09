// grouping > DFS
#include <iostream>

using namespace std;

int N;
int a[104][104];
int safe[104][104];
int visited[104][104];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void DFS(int sx, int sy)
{
	int tx,ty;
	
	visited[sx][sy] = 1;
	
	for (int i=0;i<4;i++){
		tx = sx + dx[i]	;
		ty = sy + dy[i]	;
		
		if ( tx<0 || ty<0 || tx >= N || ty >= N ) continue;
		if ( safe[tx][ty]==1 && visited[tx][ty]==0)
		{
			DFS(tx,ty);	
		}
		
	}
	
	return;
}

int main()
{
	int safeZoneCnt = 0;
	int maxCnt=0;
	int min=100, max=1;
	
	cin >> N;
	
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			cin >> a[i][j];
			if ( a[i][j] < min ) min = a[i][j];
			else if ( a[i][j] > max ) max = a[i][j];
		}
	}	
	
	for (int k=min;k<=max;k++)
	{
		safeZoneCnt = 0;
		fill(&visited[0][0],&visited[0][0]+104*104, 0); //remember
		fill(&safe[0][0],&safe[0][0]+104*104, 0);
		
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				if ( a[i][j]<k) safe[i][j] = 0;
				else safe[i][j] = 1;
			}
		}
		
		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				if ( safe[i][j]!=0 && visited[i][j]==0 )
				{
					safeZoneCnt++;
					DFS(i,j);
				}
			}
		}
		if (safeZoneCnt > maxCnt ) maxCnt = safeZoneCnt;
	}
	
	cout << maxCnt << "\n";
	
	return 0;
}

