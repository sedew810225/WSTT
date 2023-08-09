#include <iostream>
#include <vector>

using namespace std;


void rotate90toLeft(vector< vector<int> > & t){
	int m = t.size();
	vector<vector<int>> temp (m, vector<int>(m,0));
	
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			temp[i][j] = t[j][m-i-1];
		}
	}
	
	t = temp;
	return ;
}

void rotate90toRight(vector< vector<int> > & t){
	int m = t.size();
	vector<vector<int>> temp (m, vector<int>(m,0));
	
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			temp[i][j] = t[m-j-1][i];
		}
	}
	
	t = temp;
	return ;
}

int main(){
	int m = 10;
	vector<vector<int>> table(m, vector<int>(m,0));
	
	for (int i=0;i<m;i++){
		for (int j=0;j<m;j++){
			table[i][j] = i*j;
		}
	}
	
	for (int i=0;i<m;i++){
		for (auto j:table[i]) {
			cout.fill('0');
			cout.width(2);
			cout << j << " ";
		}
		cout << "\n";
	}
	
	rotate90toRight(table);
	cout << "\n";
	
	for (int i=0;i<m;i++){
		for (auto j:table[i]) {
			cout.fill('0');
			cout.width(2);
			cout << j << " ";
		}
		cout << "\n";
	}
	
	
	return 0;
}
