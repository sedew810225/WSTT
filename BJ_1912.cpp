#include <iostream>

using namespace std;

int n=0;
int maxSum=0; // consider minus
int a[100001] = {0,};

void sumSub(int foreSum, int i){
    int sum=0;

    if (i+1<n){
        sum = foreSum + a[i+1];
        if ( sum > maxSum ) maxSum = sum;
        sumSub(sum, i+1);
    } 

    return ;
}

int main(){

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> a[i];
    }

    maxSum = a[0]; // initialize maxSum;

    for (int i=0;i<n;i++){
        if ( a[i] > maxSum ) maxSum = a[i];
        sumSub(a[i],i);
    }

    cout << maxSum <<endl;

    return 0;
}

