#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	
	string dopa = "life is limited";
	
	cout << dopa.substr(0,3) << "\n";
	
	reverse (dopa.begin(), dopa.end());
	
	dopa += "dopa!!";
	
	cout << dopa << "\n";
	
	return 0;
}
