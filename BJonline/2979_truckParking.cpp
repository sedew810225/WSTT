#include <iostream>

using namespace std;

int main(){
	int timeTable[104] = {0,};
	
	int priceA, priceB, priceC;
	int totalPrice=0;
	int firstTime=100, lastTime=1;
	
	cin >> priceA >> priceB >> priceC;
	
	for (int i=0;i<3;i++){
		
		int enterTime, outTime;
		cin >> enterTime >> outTime;
		
		if (enterTime < firstTime ) firstTime = enterTime;
		if (outTime > lastTime ) lastTime = outTime;
		
		for (int i=enterTime; i<outTime; i++){
			timeTable[i]++;
		}
	}
	
	
	for (int i=firstTime;i<=lastTime;i++){
		if ( timeTable[i] == 0 ) continue;
		if ( timeTable[i] == 1 ) totalPrice += (priceA*1);
		else if ( timeTable[i] == 2 ) totalPrice += (priceB*2);
		else if ( timeTable[i] == 3 ) totalPrice += (priceC*3);
	}
	
	cout << totalPrice << "\n";
	
	return 0;
}


