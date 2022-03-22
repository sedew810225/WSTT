#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//초기화 하고나서, push_back하면 뒤에 들어감 
vector<int> target;
vector<int> selected;

int find100sum(vector<int> dwarfHeight, int num){

	if ( num == 7 )	{
		if ( accumulate(target.begin(), target.end(), 0) == 100 ) {
			sort(target.begin(), target.end());
			for (int i=0; i<target.size();i++ ) cout << target[i] << "\n";
			return 1;
		}
		return 0;
	}
	
	//앞쪽 배열을 선택하고 나서 그다음엔 선택하지 않음 
	for (int i=num;i<dwarfHeight.size();i++){
		
		target.push_back(dwarfHeight[i]);
		if ( find100sum(dwarfHeight, num+1) == 1 ) return 1;
		target.pop_back();
	}
	
	return 0;
}

int main(){
	
	vector<int> dwarfHeight(9);
	
	for (int i=0;i<9;i++) cin >> dwarfHeight[i];
	
	find100sum(dwarfHeight, 0);
	
	return 0;	
}
