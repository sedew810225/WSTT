#include <iostream>

using namespace std;

int R,C;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

char r[22][22];
int visited[22][22];
int alphabet[26];

int maxLen=0;

int dfs(int x,int y,int len)
{
	int nx,ny;
	int ret=1;

	if ( alphabet[r[x][y]-'A'] != 0 )
	{
		return 0;	
	} 
	
	visited[x][y] = 1;
	alphabet[r[x][y]-'A'] ++;
	if (len>maxLen) maxLen = len;	
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ( nx<0 || ny<0 || nx>=R || ny>=C || visited[nx][ny] ) continue;
		
		dfs(nx,ny,len+1);
		visited[nx][ny]=0;
		//cout << "-" << r[nx][ny] << " ";
		
	}
	
	//there is no place to go // flow my mind's thinking flow
	alphabet[r[x][y]-'A'] --;
	visited[x][y]=0;

	return 1;
}

int main()
{
	cin >> R >> C;

	for (int i=0;i<R;i++)
	{
		for (int j=0;j<C;j++)
		{
			cin >> r[i][j];
		}	
	}	
	
	//bfs();
	dfs(0,0,1);
	
	cout << maxLen <<"\n";
	
	return 0;
}
