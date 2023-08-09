#include <iostream>

#define totalAlpha 26

using namespace std;

int main(){
	
	string inputStr;
	getline(cin,inputStr);
	
	for (int i=0;i<inputStr.length();i++){
		
		if (inputStr[i]>='a' && inputStr[i]<='z') {	
			inputStr[i] = (inputStr[i]-'a'+13)%totalAlpha+'a';
			
		}
		else if (inputStr[i]>='A' && inputStr[i]<='Z') {
			inputStr[i] = (inputStr[i]-'A'+13)%totalAlpha+'A';
		}	
		
	}
	
	cout << inputStr << "\n";	
	
	return 0;
}

