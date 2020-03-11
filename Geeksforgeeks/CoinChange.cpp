#include <iostream>
using namespace std;
#define run 0

int coinChange() {
    int coinCount = 0;
    int targetValue = 0;
    int j = 0, i = 0;
    int ret = 0;

    cin >> coinCount;
    int* coinArray = new int[coinCount + 1];
    coinArray[0] = 0;
    for (j = 1; j <= coinCount; j++) {
        cin >> coinArray[j];
    }

    cin >> targetValue;
    int** calTable = new int* [coinCount + 1];
    for (j = 0; j <= coinCount; j++) {
        calTable[j] = new int[targetValue + 1];
    }

    for (j = 0; j <= coinCount; j++) {
        for (i = 0; i <= targetValue; i++) {
            if (i == 0 && j == 0) calTable[j][i] = 1;
            else if (coinArray[j] > i) {
                calTable[j][i] = calTable[j - 1][i];
            }
            else {
                if (j - 1 < 0) calTable[j][i] = 0;
                else calTable[j][i] = calTable[j - 1][i] + calTable[j][i - coinArray[j]];
            }
        }
    }

    ret = calTable[coinCount][targetValue];

    for (j = 0; j <= coinCount; j++) {
        delete[] calTable[j];
    }
    delete[] calTable;

    return ret;
}

#if (run==1)
int main() {
    int IssueCnt = 0;

    cin >> IssueCnt;

    while (IssueCnt) {
        cout << coinChange();
        cout << endl;
        IssueCnt--;
    }

    return 0;
}
#endif