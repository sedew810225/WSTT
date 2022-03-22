#include <iostream>
#include <vector>
using namespace std;



vector<int> era(int mx_n){
	vector<int> v;
	vector<int> che(mx_n+1);
	
	for (int i=2; i<=mx_n; i++){
		if (che[i]) continue;
		for (int j=2*i; j<=mx_n; j += i) {
			che[j] = 1;
		}
	}
	
	for(int i = 2; i <= mx_n; i++) {
		if(che[i] == 0) v.push_back(i);	
		
	} 
	return v;
}


int main(){
	vector<int> result;
	
	result = era(100);
		
	for (auto a : result) cout << a << " ";
	
	return 0;
}
