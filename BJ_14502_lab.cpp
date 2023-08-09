#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


int a[10][10];
vector< pair<int, int> > v;

int visited[10][10];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int value=0;

int N,M;

// calculate max
void calculate(int x, int y)
{
	int nx,ny;
	
	if ( visited[x][y] == 1 || a[x][y]==1 ) return;
	
	visited[x][y] = 1;
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ( nx < 0 || ny < 0 || nx >= N || ny>=M ) continue;
		calculate(nx,ny);
	}
	
}
	
// spread virus
int spreadVirus()
{
	int val=0;
	memset (visited, 0, sizeof(visited));
	
	for ( int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			if ( a[i][j] == 2) calculate(i,j);
		}
	}
	
	for ( int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			if ( visited[i][j] == 0 && a[i][j]!=1 ) val++;
		}
	}
	
	return val;
}

int main()
{
	int ret=0;
	// get input for target cell
	
	cin >> N >> M;
	
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<M;j++)
		{
			cin >> a[i][j];
			if ( a[i][j] == 0 ) v.push_back({i,j});
		}
	}
	
	// put 3 walls, consider all case
	for (int i=0;i<v.size();i++)		
	{
		for (int j=0;j<i;j++)		// combination using for loop
		{
			for (int k=0;k<j;k++)			
			{
				//cout << i << " " << j << " " << k << "\n";
				if (i==j && j==k) continue;
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 1;
				ret = max (ret, spreadVirus());
				a[v[i].first][v[i].second] = a[v[j].first][v[j].second] = a[v[k].first][v[k].second] = 0;
			}
		}
		
	}
	
	cout << ret << "\n";
	return 0;
}
	
	

