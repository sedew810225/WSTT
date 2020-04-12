#include <iostream>
#include <string>
#include <stack>
using namespace std;

#if 0
int main() {
    string inputStr;
    stack<char> aStack;
    char aChar = 0;
    int tag = 0;

    getline(cin, inputStr);

    for (int i = 0; i < inputStr.length(); i++) {

        aChar = inputStr.at(i);

        if (aChar == '<') {
            tag = 1;
        }
        else if (aChar == '>') {
            tag = 0;
        }

        if (aStack.empty() != 1 && (aChar == ' ' || aChar == '<' )) {
            while (!aStack.empty()) {
                cout << aStack.top();
                aStack.pop();
            }
        } 

        if ( tag==1 || aChar == ' ' || aChar == '<' || aChar == '>' ) {
            cout << aChar;
        } else {
            aStack.push(aChar);
        }

    }

    if (aStack.empty() != 1 ) {
        while (!aStack.empty()) {
            cout << aStack.top();
            aStack.pop();
        }
    }

    return 0;
 }
#endif