#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

unsigned long long int check(unsigned int a, unsigned int b, unsigned int c){
	unsigned long long int ret=1;
	
	if (b==1){
		return a%c;
	} else {
		ret = check(a, b/2,c)	;
		ret = (ret*ret)%c;
		if (b%2){
			ret = (ret*a)%c;
		}
	}
	return ret;
}

int main(){
	
	unsigned int a, b, c;
	unsigned long long int ret=1;
	
	cin >> a >> b >> c;
	
	// why it's not working ?
	#if 0
	if (b==1){
		ret = a%c;
	}else	if ( b%2 == 0 ){
		for (int i=0;i<b/2;i++){
			ret *= a%c;
		}
		ret = (ret*ret)%c;
	}else {
		for (int i=0;i<b/2;i++){
			ret *= a%c;
		}
		ret = (ret*ret*a)%c;		
	}
	#endif
	
	ret = check(a,b,c);
	
	cout << ret << "\n";
	
	return 0;
}
