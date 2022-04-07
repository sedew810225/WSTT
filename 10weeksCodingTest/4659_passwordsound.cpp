#include <iostream>

using namespace std;
bool rule1;
bool rule2;
bool rule3;

string str;

int main () 
{
	char prev=0;
	bool prevIsCons=false;
	bool isCons=true;
	int checkRule2=1;
		
	while (1)
	{
		prev = 0;
		prevIsCons = false;
		isCons = true;
		rule1 = false;				// use correct initialization or find another simple way
		rule2 = rule3 = true;	
		checkRule2=1;
		
		cin >> str;	
		if ( str == "end") break;
		
		for (auto a : str){
			if (a == 'a' || a == 'e' || a == 'i' || a=='o' || a=='u'){
				isCons = false;
				rule1=true;		// check more clear requirment and rule
			} else{
				isCons = true;
			}

			if (isCons == prevIsCons && prev!=0 ) checkRule2++;
			else checkRule2=1;
			
			if (checkRule2==3) {
				rule2 = false;
				break;
			}
			
			if ( (prev==a && (a=='e' || a=='o') || prev==0 )) {
				rule3 = true;
			} else if (prev==a){
				rule3 = false;
				break;
			}
			
			prev = a;			
			prevIsCons = isCons;
		}

		if ( rule1==false || rule2==false || rule3==false )	cout << "<" << str <<"> is not acceptable."<<"\n";
		else cout << "<" << str <<"> is acceptable."<<"\n";
	}
	
	return 0;
}
