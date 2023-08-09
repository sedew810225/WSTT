#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	map<string, int> monList;
	map<int, string> monList2;
		
	string monster;
	string question;
	int monCnt, questCnt;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> monCnt;
	cin >> questCnt;
	
	for (int i=0;i<monCnt;i++){
		cin >> monster;
		monList.insert({monster, i+1});
		monList2.insert({i+1, monster});
	}	
	
	for (int j=0;j<questCnt;j++){
		cin >> question;
		
		if ( question[0]>='0' && question[0]<='9' ) {
			cout << monList2[stoi(question)] << "\n";
		} else {
			cout << monList[question] << "\n";
			
		}
		
	}
	
	return 0;		
}

