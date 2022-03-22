#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

 
int main(){
	int playerNum;   // 1<=150
	string playerName;
	vector<string> playerList;
	vector<char> selectedPlayers;
	
	cin >> playerNum;
	
	for (int i=0; i<playerNum;i++){
		cin >> playerName;
		playerList.push_back(playerName);	
	} 
	
	sort ( playerList.begin(), playerList.end());

	char targetAlpha = 0;
	int count=0;	
	for ( auto a : playerList ){
		if (targetAlpha == 0 || targetAlpha != a[0]){
			targetAlpha = a[0];	
			count=1;
		} else if (targetAlpha == a[0]){
			count++;
			if (count==5) selectedPlayers.push_back(targetAlpha);
		} 
	}
	 
	if ( selectedPlayers.size() == 0 ) cout << "PREDAJA";
	else {
		for (auto a : selectedPlayers ) cout << a ;
	}
	cout << "\n";
	
	return 0;	
}

