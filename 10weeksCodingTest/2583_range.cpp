
// grouping > DFS
// read the requirement carefully

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M,N,K;

int a[104][104];
int visited[104][104];
//int idxSize[104];
vector<int> result;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void fillArea(int x1, int y1, int x2, int y2)
{
	for (int i=x1;i<=x2;i++)	
	{
		for (int j=y1;j<=y2;j++)
		{
			//cout << i << "," << j << "\n";
			a[i][j] = 1;
		}
	}
	
	return ;
}

void DFS(int sx, int sy, int idx)
{
	int tx, ty;
	
	visited[sx][sy]=1;
	result[idx]++;
	//idxSize[idx]++;
	//cout << idx << ":" << sx << "," << sy << "=" << idxSize[idx] << "\n";
	
	for (int i=0;i<4;i++)
	{
		tx = sx + dx[i];
		ty = sy + dy[i];
		
		if (tx<0 || ty<0 || tx>=M || ty>=N ) continue; // careful code checking
		if ( a[tx][ty]==0 && visited[tx][ty]==0)
		{
			DFS(tx,ty, idx);
		}
	}
	
	return;
}

int main() 
{
	int x1,y1,x2,y2;
	int id=0;
	cin >> M >> N >> K;
	
//	cout << M << "," << N << "," << K << endl;
	
	for (int i=0;i<K;i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;	//read the requirement carefully
		fillArea(x1,y1,x2-1,y2-1);		//read the requirement carefully
	}

#if 0	
	for (int i=0;i<M;i++)
	{
		for (int j=0;j<N;j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
#endif

	for (int i=0;i<M;i++)
	{
		for (int j=0;j<N;j++)
		{
			if ( a[i][j]==0 && visited[i][j]==0 )
			{
				id++;
				result.push_back(0);
				DFS(i,j, id-1);
			}
		}
	}
	
	cout << id << "\n";
	sort(result.begin(), result.end());
	
	for (int i=0;i<id;i++)
	{
		cout << result[i] <<" "; //read the requirement carefully
	}
	cout << "\n";
	
	return 0;	
}

