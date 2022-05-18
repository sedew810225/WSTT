#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int r,c;

int table[104][104];
int visited[104][104];

vector< pair<int , int > > v;
vector< pair<int , int > > temp;
vector< pair<int, int > > remained;


int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void printVisited()
{
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}

void findZeroGroup(int x, int y)
{
	int nx,ny;
	
	if ( visited[x][y]==1 || table[x][y]!=0) return;
	visited[x][y]=1;
	temp.push_back({x,y});
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if ( nx<0 || ny<0 || nx>=r || ny >=c ) continue;
		findZeroGroup(nx,ny);
	}
	
	return;
}


int checkSurroundingOne()
{
	int surrounded = 0;
	int nx,ny;
	
	for (auto a:v)
	{
		for (int i=0;i<4;i++)
		{
			nx = a.first + dx[i];
			ny = a.second + dy[i];
			if ( nx<0 || ny<0 || nx>=r || ny >=c )
			{
				surrounded=0;
				break;	
			}
			
			if (table[nx][ny]==0) continue;
			else surrounded=1;
		}		
	}
	
	return surrounded;
}

int main()
{
	int surrounded=0;
	
	cin >> r >> c;
	
	//initial input
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			cin >> table[i][j];
			
			if ( table[i][j]==1 ) remained.push_back({i,j});
		}
	}

	while ( !remained.empty() )
	{
		v.clear();
		memset(visited, 0 , sizeof(visited));
		
		for (int i=0;i<r;i++)
		{
			for (int j=0;j<c;j++)
			{
				if ( table[i][j]==0)
				{
					if (visited[i][j]==0)
					{
						temp.clear();
						findZeroGroup(i,j);
						surrounded = checkSurroundingOne();
						if (surrounded != 1 ){
							v.insert(v.end(), temp.begin(), temp.end());
						}
					}
				}
			}		
		}
		//printVisited();
		expandZero();
	}
	
	return 0;
}
