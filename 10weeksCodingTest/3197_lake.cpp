#include <iostream>
#include <queue>

using namespace std;

int b1x,b1y, b2x,b2y;

int R,C;
char lake[1504][1504];
int v[1504][1504];

struct A{
	int x;
	int y;
	int time;	
};

queue <A> q1;
queue <A> q2;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void print(){
	for(int i=0;i<R;i++){
		for (int j=0;j<C;j++)
		{
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}
	cout <<"\n";	
}

int run(int x, int y, int b,int time)
{
	int ret=0;
	int nx,ny;
	
	v[x][y] = b;
	
	for (int i=0;i<4;i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		
		if (nx<0 || ny<0 || nx>=1500 || ny>=1500) continue;
		if ( b==1 && v[nx][ny] == 1) continue;
		else if ( b==2 && v[nx][ny] == 2) continue;

		if ( b==1 && v[nx][ny] == 2) return 1;
		else if ( b==2 && v[nx][ny] == 1) return 1;
		
		if ( lake[nx][ny] == 'X')
		{
			if (b==1) q1.push({nx,ny,time+1});	
			else q2.push({nx,ny,time+1});
			
		//	v[x][y] = b;
		}
		else if ( lake[nx][ny]=='.'){
			ret = run(nx,ny,b,time);
			if (ret==1) return ret;
		}
	}
	
	return ret;					
}

int bfs()
{
	int timer=0;
	int nx,ny;
	int ret;
	
	q1.push({b1x,b1y,0});
	q2.push({b2x,b2y,0});
	
	do
	{
			while (!q1.empty())
			{
				auto b1 = q1.front();		
				if (b1.time > timer) break;
				
				q1.pop();
				v[b1.x][b1.y] = 1;
				
				for (int i=0;i<4;i++)
				{
					nx = b1.x + dx[i];
					ny = b1.y + dy[i];
					
					if (nx<0 || ny<0 || nx>=1500 || ny>=1500 || v[nx][ny]==1 ) continue;
					if ( v[nx][ny] == 2) return timer;
					else if ( lake[nx][ny] == 'X')
					{
						q1.push({nx,ny,b1.time+1});	
					}
					else if ( lake[nx][ny]=='.'){
						ret = run(nx,ny,1,b1.time);
						if (ret==1) return timer;
					}
				}					
			}
			
			while (!q2.empty())
			{
				auto b2 = q2.front();				
				if (b2.time > timer) break;
				
				q2.pop();
				v[b2.x][b2.y] = 2;
				
				for (int i=0;i<4;i++)
				{
					nx = b2.x + dx[i];
					ny = b2.y + dy[i];
					
					if (nx<0 || ny<0 || nx>=1500 || ny>=1500 || v[nx][ny]==2) continue;
					if ( v[nx][ny] == 1) return timer;
					else if ( lake[nx][ny] == 'X')
					{
						q2.push({nx,ny,b2.time+1});
					}
					else if ( lake[nx][ny]=='.'){
						ret = run(nx,ny,2,b2.time);
						if (ret==1) return timer;
					}
				}				
			}
						
		timer ++;
	} while (1);
	
	return timer;
}

int main()
{
	cin >> R >> C;
	
	b1x=b1y=b2x=b2y=-1;
	
	for (int i=0;i<R;i++)
	{
		for (int j=0;j<C;j++)
		{
			cin >> lake[i][j];
			if ( lake[i][j] == 'L'){
				if (b1x==-1){
					b1x = i;
					b1y = j;
				} else{
					b2x = i;
					b2y = j;
				}
			}
		}
	}	
	
	cout << bfs();
	return 0;
}
