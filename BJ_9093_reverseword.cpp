#include <iostream>
#include <string.h>
using namespace std;

class stack {

public:
    char array[10000] = { 0, };
    int sp = -1;

    void push(char x) {
        sp++;
        if (sp >= 10000) return;
        array[sp] = x;
    }

    char pop() {
        char returnValue;
        if (sp < 0) {
            return 0;
        }
        else {
            returnValue = array[sp];
            sp--;
            return returnValue;
        }
    }

    int size() {
        return (sp + 1);
    }

    int empty() {
        if (sp == -1) return 1;
        else return 0;
    }

    void top() {
        if (sp < 0) cout << "-1";
        else cout << array[sp];
        cout << endl;
    }
};

int reverseWord(char* inputStr) {
    char* ptrStr = NULL;
    int wordLength = 0;
    ptrStr = inputStr;
    
    stack aStack = stack();
    
    if (ptrStr == NULL) return -1;

    while(1) {
        if ((*ptrStr == ' ') || (*ptrStr == 0)) {
            wordLength = aStack.size();
            while (wordLength > 0) {
                cout << aStack.pop();
                wordLength--;
            }

            if (*ptrStr == ' ') cout << *ptrStr;
            else if (*ptrStr == 0) break;
        }
        else {
            aStack.push(*ptrStr);
        }
        
        ptrStr++;
    }
    cout << endl;

    return 0;
}
#if 0
int main() {
	char inputStr[1001];
	unsigned int IssueCnt = 0;

	cin >> IssueCnt;
    cin.ignore();

	while (IssueCnt > 0) {
		memset(inputStr, 0, sizeof(inputStr));
		cin.getline(inputStr, sizeof(inputStr));
		reverseWord(inputStr);
		IssueCnt--;
	}

	return 0;
}
#endif