#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

//연산자 선택 조합  << 문제의 근본 특성 파악 필요 
//1개부터 n개까지, 중첩 허용,근접은 제외 
//선택된 연산자 계산값 치환
//다시 전체 계산
 
vector <char> operands;
vector <int> numbers;
vector <int> selected;

int resultA[9];
int resultVisited[10];

bool visited[19];

int maxCal=-987654321;

int cal2(int op1, int op2, int idx)
{
	switch ( operands[idx] )
	{
		case '+' :
			return op1+op2;
		case '-' :
			return op1-op2;
		case '*' :
			return op1*op2;
	}
	return 0;
}

int cal (int idx)
{
	switch ( operands[idx] )
	{
		case '+' :
			return numbers[idx]+numbers[idx+1];
		case '-' :
			return numbers[idx]-numbers[idx+1];
		case '*' :
			return numbers[idx]*numbers[idx+1];
	}
	return 0;
}

int priority(int cnt)
{
	int bFlag, aFlag;
	int op1, op2;
	
	if ( cnt >= operands.size()) return 0;
	
	for (int i=0;i<operands.size();i++)
	{
		if ( visited[i]==true ) continue;
		bFlag = 0;		// needs correct initialization
		aFlag = 0;	
			
		selected.push_back(i);

		visited[i] = true;		
		if ( i-1 >=0 && visited[i-1]==false){
			visited[i-1]=true;
			bFlag = 1;	
		}
		if ( i+1 < operands.size() && visited[i+1]==false ) {
			visited[i+1]=true;
			aFlag = 1;
		}
		
		memset(resultA, -1, sizeof(resultA));
		memset(resultVisited, -1, sizeof(resultVisited));
		
		for (auto j : selected){
			resultA[j] = cal(j);
			resultVisited[j] = 1;
			//cout << j << ":" << resultA[j] << " " ; 
		} 
		//cout << "\n";
		
		#if 1
		for (int k=0;k<operands.size();k++){
			if ( resultVisited[k]==-1)
			{
				if (k==0) op1 = numbers[0];
				else op1 = resultA[k-1];
				
				if (k+1>=operands.size() || resultVisited[k+1]==-1) op2 = numbers[k+1];
				else op2 = resultA[k+1];
						
				resultA[k] = cal2(op1,op2,k);
				resultVisited[k] = 1;
				
				if ( k+1<operands.size() && resultVisited[k+1]!=-1 ) 
				{
					resultA[k+1] = resultA[k];	//careful to check overflow
				}
			}	
		}
		if ( maxCal < resultA[operands.size()-1]) maxCal = resultA[operands.size()-1];	// use correct index
		#endif
		
		priority(cnt+1);
		
		selected.pop_back();	// erase(selected.end() not working		
		visited[i] = false;
		if ( i-1 >=0 && bFlag == 1) visited[i-1]=false;
		if ( i+1 < operands.size() && aFlag == 1 ) {
			visited[i+1]=false;
		}
	}
	
	return 0;
}

int main()
{
	int N;
	char a;
	
	cin >> N;
	for (int i=0;i<N;i++)
	{
		cin >> a;
		if ( a>='0' && a<='9' ) numbers.push_back(a-'0');	//wrong value handling
		else operands.push_back(a);
	}

	if (N==1) {						//Needs careful checking the input requirement
		maxCal = numbers[0];
	} else
	{
		priority(0);
	}	
	cout << maxCal <<"\n";
	
	return 0;
}
