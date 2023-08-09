// grouping > DFS
// calculate union people number for each groups
// repeat

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <string.h>

using namespace std;

int N, L, R;

int a[52][52];
int v[52][52];

vector < pair<int, int> > group;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void dfs(int x , int y)
{
	int nx, ny;
	int diff;
	if ( v[x][y]==1 ) return;
	v[x][y]=1;
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];

		if (nx<0 || ny<0 || nx>=N || ny>=N ) continue;
		if (v[nx][ny]==1 ) continue;					// check correct condition to skip
		
		diff = abs(a[nx][ny] - a[x][y]);
		if ( diff >= L && diff <= R	){
			group.push_back({x,y});
			group.push_back({nx,ny});
			dfs(nx,ny);
		} 
	}
	
	return;
}


int main()
{
	int subCal=0;
	int days=0;
	bool united=false;
	
	cin >> N >> L >> R;
	
	
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			cin >> a[i][j];
		}
	}


	// one open calculation
	while(1)
	{
		united = false;				// use correct flag
		memset(v, 0, sizeof(v));	// use correct intialization
		group.clear();				// use correct intialization

		for (int i=0;i<N;i++)
		{
			for (int j=0;j<N;j++)
			{
				if ( v[i][j] == 1) continue;
				
				subCal = 0;
				group.clear();
				
				dfs(i,j);
		
				sort(group.begin(), group.end());								//should memory this part
				group.erase(unique(group.begin(), group.end()), group.end());
				
				if ( !group.empty() )
				{
					united = true;
					for (auto u : group)
					{
							subCal += a[u.first][u.second];
					}
					
					subCal = subCal / group.size();
					
					for (auto u : group)
					{
							a[u.first][u.second] = subCal;
					}
				}
			}
		}
		
		if (united)
		{
			days++;			
		} 
		else break;	// find appropriate exit condition
	}

	cout << days << "\n";
	
	return 0;
}



