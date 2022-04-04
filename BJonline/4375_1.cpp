#include <iostream>
using namespace std;

typedef unsigned long long ll;

// Time excess

int solution(ll input){
	ll multiTen=1;
	int digits=0;
	
	if (input==1) return 1;
	else {
		for (digits=1;;digits++){
			if (digits==1) remain = 1;
			else {
				multiTen = ( multiTen*(10%input) + 1 )%input;
				//cout << multiTen << "+";
				
				if ( multiTen==0 ) return digits;
			}
		}	
	}
	//cout << "\n";
	
	return -1;
}

int main(){
	
	ll input;
	int result=0;
	while( scanf("%d",&input) !=EOF ){	
		result = solution(input);
		cout << result << "\n";
	}
	return 0;
}
