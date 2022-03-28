#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


// read the assignment very carefully for the limitation ore requirement

int main(){
	string nameStr;
	string result;
	
	char target;
	int position=-1;
	int odd;
	char center=0;
	 
	cin >> nameStr;
	
	odd = nameStr.length()%2;
	//even
	for (;nameStr.length()>0;){
		target = nameStr[0];
		result.push_back(target);		
		nameStr.erase(0,1);
		
		position = nameStr.find(target) ;
		if ( position != string::npos) nameStr.erase(position, 1);
		else {
			if (center==0){
				result.pop_back();
				center = target;	
			} else {
				cout << "I'm Sorry Hansoo\n";
				return 0;	
			}
		}	
	}
	
	sort (result.begin(), result.end());
	
	cout << result ;
	if (center!=0) cout << center ;
	reverse (result.begin(), result.end());
	cout << result << "\n";
	
	return 0;
}
