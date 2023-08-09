#include <iostream>
#include <string>
#include <stack>
using namespace std;

#if 0
int main() {
    int issueCnt = 0;
    int targetValue = 0;
    string resultArray;
    stack <int> aStack;
    int num = 1;
    int top = 0;

    cin >> issueCnt;

    cin.ignore();

    for (int i = 0; i < issueCnt; i++) {
        cin >> targetValue;
        cin.ignore();

        if (targetValue >= num) {

            if (num > issueCnt) {
                cout << "NO" << endl;
                return 0;
            }

            while (targetValue >= num) {
                aStack.push(num);
                num++;
                resultArray += "+";
            }

            if (aStack.top() == targetValue) {
                aStack.pop();
                resultArray += "-";
            }

        } else {
            if (aStack.top() == targetValue) {
                aStack.pop();
                resultArray += "-";
            }
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    for (auto x : resultArray) {
        cout << x << '\n';
    }

    return 0;
}
#endif