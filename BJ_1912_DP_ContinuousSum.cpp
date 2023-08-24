// 가장 큰 합을 구하기
// 반복되서 리컬시브하게 구할 수 있는데
// 이전까지 구한 최대값 + 현재값 -> DP
// 이전 + 현재값이 현재값 보다 작다면, 현재값이 최대가 됨

#include <iostream>

using namespace std;

int dp[100001] = {0,};
int dt[100001] = {0,};
int n=0;
int maxNum=0 ;

// L to R
void dpL2R () {

    dp[0] = dt[0];
    maxNum = dp[0];

    for (int i=1;i<n;i++){
        dp[i] = max (dp[i-1]+dt[i], dt[i]);
        if ( dp[i] > maxNum ) maxNum = dp[i];
    }

    return ;
}

// R to L
void dpR2L () {

    dp[n-1] = dt[n-1];
    maxNum = dp[n-1];

    for (int i=n-2;i>=0;i--){
        dp[i] = max (dp[i+1]+dt[i], dt[i]);
        if ( dp[i] > maxNum ) maxNum = dp[i];
    }

}

int main(){
        
    cin >> n;

    for (int i=0;i<n;i++){
        cin >> dt[i];
    }

    //dpL2R();
    dpR2L();

    cout << maxNum << endl;

    return 0;
}