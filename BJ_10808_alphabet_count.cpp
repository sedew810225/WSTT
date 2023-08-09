#include <iostream>

using namespace std;
int countArray['z'-'a'+1] = {0,};

int main(){
	string input;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> input;

	for (char a : input){
		if ( a < 'a' || a > 'z') continue;
		countArray[a-'a']++;
	} 
	
	for (int i=0; i<'z'-'a'+1; i++){
		cout << countArray[i] << " ";
	} 
	
	return 0;	
}

