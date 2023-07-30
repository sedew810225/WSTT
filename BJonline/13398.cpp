#include <iostream>

using namespace std;

int n=0;
int maxSum=0; // consider minus
int subMin=0;

int a[100001] = {0,};

int findMin(int start, int end){
    int min = a[start];

    for (int i=start;i<end;i++){
            if ( a[i] < min ) min = a[i];
    }

    return min;
}

//n개에서 k개 선택하기
//그중에서 잴 작은애 빼기
void sumSub(int foreSum, int start, int end){
    int sum=0;
    int sum2=0;
    int temp=0;

    if (end+1<n){
        if ( a[end+1] < subMin ) subMin = a[end+1];
    
        sum = foreSum + a[end+1];    
        sum2 = sum - subMin;

        if (sum2 > sum) temp = sum2;
        else temp = sum;

        if ( temp > maxSum ) maxSum = temp;

        sumSub(sum, start, end+1);
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

        subMin = a[i];
        sumSub(a[i],i,i);
    }

    cout << maxSum <<endl;

    return 0;
}

