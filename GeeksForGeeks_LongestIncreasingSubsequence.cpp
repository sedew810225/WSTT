#include <iostream>
#include <cstring>

using namespace std;

int findMaxSub(int i, int** tempA, int cnt) {
    int subLen = 0;
    int j = 0;
    int max = 0;

    if (i >= cnt - 1) return 1;

    for (j = i + 1; j < cnt; j++) {
        if (tempA[i][j] == 1) {
            subLen = findMaxSub(j, tempA, cnt) + 1;
            if (subLen > max) max = subLen;
        }
    }

    return max;
}

int longestAsndSub(int* array, int cnt) {
    int** tempA;
    int i = 0, j = 0;
    int len = 0, max = 0;
    tempA = new int* [cnt];

    for (i = 0; i < cnt; i++) {
        tempA[i] = new int[cnt];
        memset(tempA[i], 0, sizeof(int) * cnt);

        tempA[i][i] = 1;
    }

    for (i = 0; i < cnt; i++) {
        for (j = i; j < cnt; j++) {
            if (array[i] < array[j]) {
                tempA[i][j] = 1;
            }
        }
    }

    for (i = 0; i < cnt; i++) {
        len = findMaxSub(i, tempA, cnt);
        if (len > max) max = len;
    }

    delete[] tempA;

    return max;
}

int longestAsndSubDP(int* array, int cnt) {
    int* DParray = new int[cnt];
    int i = 0, j = 0;
    int max = 1;
    int subMax = 1;

    DParray[0] = 1;
    if (cnt == 1) return 1;

    for (i = 1; i < cnt; i++) {
        subMax = 1;
        max = 1;

        for (j = 0; j < i; j++) {
            if (array[i] > array[j]) subMax = DParray[j] + 1;
            else subMax = 1;
            if (subMax > max) max = subMax;
        }
        DParray[i] = max;
    }

    for (i = 0; i < cnt; i++) {
        if (DParray[i] > max) max = DParray[i];
    }

    delete DParray;
    return max;
}

#if 0

int main() {
    int issueCnt = 0, count = 0;
    int* array;
    int i = 0;

    cin >> issueCnt;


    while (issueCnt > 0) {
        cin >> count;

        array = new int[count];
        memset(array, 0, sizeof(int) * count);
        for (i = 0; i < count; i++) {
            cin >> array[i];
        }

        cout << longestAsndSubDP(array, count) << "\n";

        delete array;
        issueCnt--;
    }
    return 0;
}
#endif
