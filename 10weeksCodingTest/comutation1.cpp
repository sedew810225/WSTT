#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n = 5;
int k = 3;
int a[5] = {1, 2, 3, 4, 5};
vector<int> b;

void print(vector<int> b){
	for(int i = 0; i < b.size(); i++){
		cout << b[i] << " ";
	}
	cout << endl;
}

void combi(int start, vector<int> b){

	if (b.size()==k){
		print(b);
		return;
	}
	
	for ( int i=start+1; i<n;i++){
		cout << " i:" << i <<"\n";
		b.push_back(a[i]);
		combi(i,b);
		b.pop_back();
	}
	
	return;

}

int main() {
	combi(-1, b);
	return 0;
}
