#include <iostream>
using namespace std;

int main(){
	string input;
	int length, i;
	int result=1;
	
	cin >> input;
	
	length = input.length();
	
	for (i=length-1; i>=length/2 ; i--){
		if ( input[i] == input[length-i-1]) continue;
		else {
			result = 0;
			break;
		}
	}
	
	cout << result <<"\n";
	
	return 0;
}

