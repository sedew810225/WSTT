#include <iostream>
using namespace std;

class stack {

public:
    int array[10000];
    int sp = -1;

    void push(int x) {
        sp++;
        if (sp >= 10000) return;
        array[sp] = x;
    }

    void pop() {
        if (sp < 0) {
            cout << "-1" << endl;
        }
        else {
            cout << array[sp] << endl;
            sp--;
        }
    }

    void size() {
        cout << sp + 1 << endl;
    }

    void empty() {
        if (sp == -1) cout << "1";
        else cout << "0";
        cout << endl;
    }

    void top() {
        if (sp < 0) cout << "-1";
        else cout << array[sp];
        cout << endl;
    }
};

int main() {
    string com;
    int value = 0, cmdCount = 0;

    stack aStack = stack();

    cin >> cmdCount;

    if (cmdCount < 0 || cmdCount > 10000) return -1;

    while (cmdCount > 0) {

        cin >> com;

        if (com.compare("push") == 0) {
            cin >> value;
            aStack.push(value);
        }
        else if (com.compare("pop") == 0) {
            aStack.pop();
        }
        else if (com.compare("size") == 0) {
            aStack.size();
        }
        else if (com.compare("top") == 0) {
            aStack.top();
        }
        else if (com.compare("empty") == 0) {
            aStack.empty();
        }

        cmdCount--;
    }
    return 0;
}