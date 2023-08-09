#include <iostream>
#include <stack>

using namespace std;

int checkGoodWord(string in){
	stack<char> buffer;
	string check;
	int beforeIdx=0;
	char prev = 0;
		
	for (int j=0;j<in.length();j++){
		if ( j==0 || prev==0 ) {
			prev = in[j];
			buffer.push(prev);	
		} else if ( in[j] == prev ) {
			buffer.pop();
			if ( buffer.size() !=0 ) prev = buffer.top();
			else prev = 0;
			
		} else if ( in[j] != prev ) {
			prev = in[j];
			buffer.push(prev);
		}
	}
	
	if ( buffer.size() == 0 ) return 1;
	
	return 0;
}

int main(){
	
	
	string input;
	
	int cnt;
	int result=0;
	
	cin >> cnt;
	
	for (int i=0;i<cnt;i++){
		cin >> input;
		result += checkGoodWord(input);
	}

	cout << result <<"\n";
	
	return 0;
}
