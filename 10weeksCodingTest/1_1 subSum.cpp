#include <iostream>

using namespace std;


int main(){
	int arrayN[100000] = { 0 };
	int subSum[100000] = { 0 };
	int arrayM[100000] = { 0 };
	int A=0, B=0;
	int N=0, M=0;
	int i=0;
	
	//cin >> N;
	//cin >> M;
	cin >> N >> M;
	
	for (i=0;i<N;i++){
		cin >> arrayN[i];
		if (i==0) subSum[i] = arrayN[i];
		else {
			subSum[i] = subSum[i-1] + arrayN[i];
		}
	}
	
	for (i=0;i<M;i++){
		//cin >> A;
		//cin >> B;
		cin >> A >> B;	
		
		if ( A != 1) arrayM[i] = subSum[B-1] - subSum[A-2];
		else arrayM[i] = subSum[B-1];
	}
	
	for (i=0;i<M;i++){
		cout << arrayM[i] << "\n";
	}
	
	return 0;
}
