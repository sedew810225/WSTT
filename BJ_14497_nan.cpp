#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int N,M;
int sx,sy,tx,ty;

char cr[304][304];
int visited[304][304];

// to reduce memory size, following should be reconsidered
struct A{
	int x;
	int y;
	int cnt;	
};
queue <A> q;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int addZero(int x, int y, int cnt)
{
	int nx,ny;
	int ret=0;
	
	visited[x][y]=cnt;
	
	for (int i=0;i<4;i++){
		nx = x + dx[i];
		ny = y + dy[i];
			
		if (nx<1 || ny<1 || nx>300 || ny>300 ) continue;
		if (visited[nx][ny]!=-1) continue;
		
		if (cr[nx][ny]=='1' )	//be careful for condition check 
		{
			q.push({nx,ny,cnt+1});	
		}
		else if (cr[nx][ny]=='0') 
		{
			ret = addZero(nx,ny,cnt);
			if (ret!=0) return ret;	
		}
		else if (cr[nx][ny]=='#'){
			return cnt+1;
		}
	}
	
	return 0;
}

int bfs (int x, int y, int cnt)
{
	int nx,ny;
	int ret=0;
	
	q.push({x,y,cnt});	
	visited[x][y] = cnt;

	while (!q.empty())
	{
		auto item = q.front();
		q.pop();
		visited[item.x][item.y]= item.cnt;
				
		for (int i=0;i<4;i++){
			nx = item.x + dx[i];
			ny = item.y + dy[i];
			
			if (nx<1 || ny<1 || nx>300 || ny>300 ) continue;
			if (visited[nx][ny]!=-1) continue;
			
			if (cr[nx][ny]=='1' ) 
			{
				q.push({nx,ny,item.cnt+1});	
			}
			else if (cr[nx][ny]=='0'){
				ret = addZero(nx,ny,item.cnt);
				if (ret!=0) return ret;
			} 
			else if (cr[nx][ny]=='#'){
				return item.cnt+1;
			}
		}			
	}

	return 0;
}

int main()
{
	int ret=0;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> sx >> sy >> tx >> ty;
	
	memset(visited, -1, sizeof(visited));
	
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=M;j++)
		{
			cin >> cr[i][j] ;
		}	
	}
	
	ret = bfs(sx,sy,0);

#if 0
	for (int i=1;i<=N;i++)
	{
		for (int j=1;j<=M;j++)
		{
			cout << visited[i][j] <<" " ;
		}	
		cout << "\n";
	}	
#endif

	cout << ret << "\n";
	return 0;
}
