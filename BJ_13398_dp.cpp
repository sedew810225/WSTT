// 가장 큰 합을 구하기
// 반복되서 리컬시브하게 구할 수 있는데
// 이전까지 구한 최대값 + 현재값 -> DP
// 이전 + 현재값이 현재값 보다 작다면, 현재값이 최대가 됨  -> inclusive

// K를 뺀다는 이야기는 -> exclusive
    //   왼쪽부터 K 직전까지 값 + K 값, 오른쪽 부터 K 직전까지의 값 + K 값, 그리고 

#include <iostream>

using namespace std;

int dpL2R[100002] = {0,};
int dpR2L[100002] = {0,};
int dt[100001] = {0,};
int n=0;
int maxNumL2R=0 ;
int maxNumR2L=0 ;
int maxNum=0;

// L to R
void dpL2Rfunc () {

    dpL2R[0] = dt[0];
    maxNum = dpL2R[0];

    for (int i=1;i<n;i++){
        dpL2R[i] = max (dpL2R[i-1]+dt[i], dt[i]);
        if ( dpL2R[i] > maxNumL2R ) maxNumL2R = dpL2R[i];
    }

    return ;
}

void dpR2Lfunc () {

    dpR2L[n-1] = dt[n-1];
    maxNum = dpR2L[n-1];

    for (int i=n-2;i>=0;i--){
        dpR2L[i] = max (dpR2L[i+1]+dt[i], dt[i]);
        if ( dpR2L[i] > maxNumR2L ) maxNumR2L = dpR2L[i];
    }

    return ;
}

int main(){
    int temp=0;

    cin >> n;

    for (int i=0;i<n;i++){
        cin >> dt[i];
    }

    dpL2Rfunc();
    dpR2Lfunc();
    maxNum = maxNumL2R;

    for (int i=1;i<n-1;i++){
        temp = dpL2R[i-1] + dpR2L[i+1];
        if ( maxNum < temp ) maxNum = temp;
    }

    cout << maxNum << endl;

    return 0;
}