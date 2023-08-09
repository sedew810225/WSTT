#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

char a[1002][1002];
char visitedF[1002][1002];
char visitedA[1002][1002];

int R,C;
int minLev = 987654321;

queue < tuple<int,int,int> > q;
queue < tuple<int,int,int> > fire_q;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};

int BFS()
{
	int Fx, Fy;
	int Jx, Jy;
	
	int nFx, nFy;
	int nJx, nJy;
	
	int fireLevel=0;
	int level=0, step=-1;
	
	int fireSize, qSize;
	
	while( !q.empty() )
	{
		fireSize = fire_q.size();
		qSize = q.size();
		
		while ( fireSize-- )
		{
			tie(Fx,Fy,fireLevel) = fire_q.front();
			fire_q.pop();
			
			for (int i=0;i<4;i++)
			{
				nFx = Fx + dx[i];
				nFy = Fy + dy[i];
				
				if ( nFx <0 || nFy <0 || nFx >= R || nFy >=C ) continue;
				if ( a[nFx][nFy] == 'F' || a[nFx][nFy]=='#') continue;  //careful to use check condition
				a[nFx][nFy] = 'F';
				
				fire_q.push(make_tuple(nFx,nFy,fireLevel+1));
			}
		}
		
		while ( qSize-- ) 
		{
			tie(Jx,Jy,level)= q.front();
			q.pop();
			
			//if (a[Jx][Jy]=='F') continue;		//Wrong code
		
			// move next step avoid fire and walls
			for (int i=0;i<4;i++)
			{
				nJx = Jx + dx[i];
				nJy = Jy + dy[i];
				
				if (visitedA[nJx][nJy]!=0 || a[nJx][nJy] == 'F' || a[nJx][nJy]=='#') continue;
				if ( nJx <0 || nJy <0 || nJx >= R || nJy >=C ) 
				{
					return level + 1;
				}
				q.push ( make_tuple(nJx, nJy, level+1));
				visitedA[nJx][nJy] = visitedA[Jx][Jy] + 1;
			}
		}	
	}
	return -1;
}

int main()
{
	int Jx, Jy;
	cin.tie(0);
    cout.tie(0);
    
	cin >> R >> C;
	
	for (int i=0;i<R;i++)
	{
		for (int j=0;j<C;j++)
		{
			cin >> a[i][j];
			if ( a[i][j]=='J')
			{
				q.push(make_tuple(i,j,0));
				visitedA[i][j] = 1;
			} else if (a[i][j]=='F')
			{
				fire_q.push(make_tuple(i,j,0));
			}
		}
	}
	
	minLev = BFS();
	
	if ( minLev == -1 ) cout << "IMPOSSIBLE";
	else cout << minLev <<"\n";
	
	return 0;	
}
