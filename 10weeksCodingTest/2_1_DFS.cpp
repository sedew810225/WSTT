#include <iostream>

using namespace std;

int a[104][104];
bool visited[104][104];

int M=0,N=0;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int dfs(int x, int y){
	int nx,ny;
	cout << y << " : " << x << '\n';

	visited[x][y] = 1;
	
	for (int i=0;i<4;i++){
		nx = x+dx[i];
		ny = y+dy[i];
		if ( nx<0 || ny<0 || nx>=N || ny >=M ) continue;
		
		if ( a[nx][ny]==1 && visited[nx][ny]!=1){
			dfs(nx,ny);
		}
	}
	
}

int main(){

	int cnt=0;
	
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> M >> N;
	
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> a[i][j] ;
		}
	}
	
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			if ( a[i][j]==1 && visited[i][j]!=1){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout << cnt << "\n";
	
	return 0;
}
