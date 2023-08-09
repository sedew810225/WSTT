#include <iostream>
#include <vector>
using namespace std;

int main(){
	string inputPat;
	string inputStr;
	vector<string> result;
	
	int cntStr;
	int checked;
	
	cin >> cntStr;
	cin >> inputPat;
	 
	//모든 케이스를 모두 디버깅 하기 힘듬 
	for (int i=0;i<cntStr;i++){
		cin >> inputStr;
		
		int fi=0;
		int pi=0;
		int si=0;
		
		//check front pattern
		for (;fi<inputPat.length() && fi<inputStr.length() && inputPat[fi]!='*';fi++){
			if ( inputPat[fi] == inputStr[fi]) {
					checked = 1;
			} else {	
			 checked = 0;
			 break;
			}
		}
		if (inputPat[fi] !='*') checked = 0;
				
		//check last pattern
		if ( checked ==1 && inputPat[fi]=='*' ){
			pi = inputPat.length()-1;
			si = inputStr.length()-1;
			
			for (; inputPat[pi]!='*' && pi>0 && si>0 && si>=fi ; pi--, si-- ){
				if ( inputPat[pi] == inputStr[si]) {
					checked = 1;
				} else {
					checked = 0;
					break;
				}
			}
			if (inputPat[pi] !='*') checked = 0;
		}
		
		if (checked == 1) result.push_back("DA");
		else result.push_back("NE");
	}
	
	for (auto a : result) cout << a << "\n";

	return 0;									
}

