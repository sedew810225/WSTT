//grouping // DFS

#include <iostream>

using namespace std;

int N,M;
int a[54][54];
bool visited[54][54];

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void DFS(int sx, int sy){
	int tx,ty;
	
	visited[sx][sy]=1;
	
	for (int i=0;i<4;i++)
	{
		tx = sx + dx[i]	;
		ty = sy + dy[i]	;
		
		if ( tx<0 || ty<0 || tx >= M || ty >= N ) continue; //remember
		if (  a[tx][ty] !=0 && visited[tx][ty]!=1 )
		{
			DFS(tx,ty);
		}
	}
	
	return;
}

int main()
{
	int issueCnt;

	int cabageCnt;
	int wormCnt=0;	
	int x,y;
	
	cin >> issueCnt;
	
	for (int j=0;j<issueCnt;j++)
	{
		wormCnt=0;	
		
		fill(&a[0][0], &a[0][0] + 54 * 54, 0); // remember init
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0); // remember init
			
		cin >> M >> N >> cabageCnt;	// remember
		
		for (int i=0;i<cabageCnt;i++)
		{
			cin >> x >> y;
			a[x][y] = 1;
		}
		
		for (int k=0;k<M;k++)
		{
			for (int l=0;l<N;l++)
			{
				if ( a[k][l]!=0 && visited[k][l]==0) //remember
				{
					wormCnt++;
					DFS(k,l);
				}
			}
		}
		
		cout << wormCnt << "\n";
	}
	
	return 0;
}




