#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

queue< pair<int,int> > q;
int a[104][104];
int visited[104][104];
int N,M;

int dx[4] = { 0, 1, 0, -1};
int dy[4] = { 1, 0,-1, 0};

void bfs(int sx, int sy){
	int nx,ny;
	int x,y;
	
	visited[sx][sy] = 1;
	q.push({sx,sy});
		
	while (q.size()){
		tie(x,y) = q.front();
		q.pop();
		
		for (int i=0;i<4;i++){
			nx = x + dx[i];
			ny = y + dy[i];
			
			if ( nx<0 || ny<0 || nx>=N || ny>=M ) continue;
			
			if ( a[nx][ny]==1 && visited[nx][ny]==0){
				visited[nx][ny] = visited[x][y]+1;
				q.push({nx,ny});
			}
		}
	}
	
	return;
}

int main(){

	int sx,sy;
	int tx,ty;
	
	cin >> N >> M;
	cin >> sy >> sx;
	cin >> ty >> tx;
	
	for (int i=0;i<N;i++){
		for (int j=0;j<M;j++){
			cin >> a[i][j];
		}
	}
	
	bfs(sx,sy);
	
	cout << visited[tx][ty] << "\n";
	
	for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
        	cout << visited[i][j] << ' '; 
        }
        cout << '\n';
    } 

	return 0;
}


