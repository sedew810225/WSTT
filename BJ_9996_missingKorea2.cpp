#include <iostream>
#include <vector>
using namespace std;

int main(){
	string inputPat;
	string frontPat;
	string endPat;
	
	vector<string> result;
	
	int cntStr;
	int checked;
	int stari;
	
	cin >> cntStr;
	cin >> inputPat;
	
	stari = inputPat.find("*");
	frontPat = inputPat.substr(0,stari);
	endPat = inputPat.substr(stari+1,inputPat.length()-1);
	
	for (int i=0;i<cntStr;i++){
		string inputStr;
		cin >> inputStr;

		checked = 0;
		
		//check front pattern
		if ( inputStr.length() >= frontPat.length()+endPat.length()) {
			if ( (frontPat == inputStr.substr(0, frontPat.length())) &&
				 (endPat == inputStr.substr(inputStr.length()-endPat.length())) ) 
				 	checked = 1;
		}
		
		if ( checked ==1 ) result.push_back("DA");
		else result.push_back("NE");
	}	
	
	for (auto a : result) cout << a << "\n";

	return 0;									
}

