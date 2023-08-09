#include <iostream>
#include <vector>

using namespace std;

int main(){
	int itemCnt;
	int M, item;
	int result=0;
	
	vector<int> items;

	cin >> itemCnt;
	cin >> M;
	
	// adding restriction or requirements
	if (M>200000){
		cout << 0 << "\n";
		return 0;	
	} 
	
	for (int i=0;i<itemCnt;i++){
		cin >> item;
		items.push_back(item);
	}
	
	for (int i=0;i<itemCnt-1;i++){
		for (int j=i+1;j<itemCnt;j++){
			if ( items[i] + items[j] == M ) result++;
		}
		
	}
		
	cout << result << "\n";
	
	return 0;
}
