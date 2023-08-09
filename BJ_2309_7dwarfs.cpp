#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

//�ʱ�ȭ �ϰ���, push_back�ϸ� �ڿ� �� 
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
	
	//���� �迭�� �����ϰ� ���� �״����� �������� ���� 
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
