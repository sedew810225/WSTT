#include <string.h>
#include <iostream>
using namespace std;

class stack {

public:
    char array[50] = { 0, };
    int sp = -1;
    
    int push(char x) {
        if (sp >= 49) return -1;
        sp++;
        array[sp] = x;
        return 0;
    }

    int pop() {
        if (sp < 0) {
            return -1;
        }
        else {
            sp--;
        }
        return 0;
    }

    int size() {
       return sp + 1;
    }

    int isEmpty() {
        if (sp == -1) return 1;
        else return 0;
    }

    void empty() {
        sp = -1;
    }
};

int checkVPS(char* inputStr){
    int index = 0;
    char value = 0;
    int fail = 0;

    stack aStack = stack();
    aStack.empty();

    if (!inputStr) return -1;

    while (inputStr[index] != 0) {
        value = inputStr[index];

        if (value == '(') aStack.push('(');
        else if (value == ')') {
            if (aStack.size() == 0) {
                fail = 1;
                break;
            }
            aStack.pop();
        }
        index++;
    }

    if ( (fail != 1) && aStack.size() == 0) cout << "YES";
    else cout << "NO";

    cout << endl;

    return 0;
}

#if 0
int main() {
	unsigned int issueCnt = 0;
    char inputStr[51];
    
	cin >> issueCnt;
	cin.ignore();

    while (issueCnt > 0) {
            memset(inputStr, 0, sizeof(inputStr));
            cin.getline(inputStr, sizeof(inputStr));
            inputStr[50] = 0;
            checkVPS(inputStr);
            issueCnt--;
     }

	return 0;
}
#endif

