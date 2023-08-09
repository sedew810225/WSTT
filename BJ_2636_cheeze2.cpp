#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int r,c;

int table[104][104];
int visited[104][104];

vector < pair<int,int> > boundary;
int boundaryCnt;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void findBoundary(int x, int y)
{
	int nx,ny;
	
	if ( visited[x][y]==1 )	return;
	visited[x][y] = 1;
	
	if ( table[x][y]==1)
	{
		boundary.push_back({x,y});
		boundaryCnt++;
		return;
	}
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ( nx<0 || ny<0 || nx>=r || ny >=c ) continue;
		findBoundary(nx,ny);
	}
	
	return;
}

int main()
{
	int lastCnt=0;
	int time=-1;
	
	cin >> r >> c;
	
	//initial input
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			cin >> table[i][j];
		}
	}

	// find boundary from wall only
	do 
	{
		lastCnt = boundaryCnt;
		boundaryCnt = 0;

		boundary.clear();
		memset(visited, 0 , sizeof(visited));
		
		for (int i=0;i<r;i++){
			findBoundary(i,0);
			findBoundary(i,c-1);
		} 
		for (int j=0;j<c;j++){
			findBoundary(0,j);
			findBoundary(r-1,j);
		}
			
		// change boundary to zero
		for (auto a: boundary)
		{
			table[a.first][a.second] = 0;	
		}
		time++;
		
	} while (! boundary.empty());
	
	cout << time << "\n" << lastCnt <<"\n";
	
	return 0;	
}
