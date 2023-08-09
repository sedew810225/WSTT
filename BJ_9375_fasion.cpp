#include <iostream>
#include <vector>
#include <map>

using namespace std;


// using math !!!!

int main(){
	
	int groupCnt;
	int itemCnt;
	
	
	cin >> groupCnt;
	
	for (int i=0;i<groupCnt;i++){
		map <string, int> mapCategory;
	
		int result=1;			
		
		cin >> itemCnt;	
		string item, category;
		
		for (int j=0;j<itemCnt;j++){
			cin >> item;
			cin >> category;
			mapCategory[category]++;
		}
		
		for (auto a : mapCategory){
			result *= (a.second+1);
		} 
	 	result--;
	 	cout << result << "\n";
	}

	return 0;
}
 
