#include <iostream>
#include <string>
using namespace std;

#if 0
int main() {
	string inputStr;
	int cntSticks = 0;
	int totalCuts = 0;

	getline(cin, inputStr);

	for (int i = 0; i < inputStr.length(); i++) {
		if (inputStr.at(i) == '(' && inputStr.at(i + 1) == ')') {
			totalCuts += cntSticks;
			i++;
		}
		else if (inputStr.at(i) == '(') {
			cntSticks++;
		}
		else if (inputStr.at(i) == ')') {
			totalCuts += 1;
			cntSticks--;
		}
	}

	cout << totalCuts <<endl;

}
#endif