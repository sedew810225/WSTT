#include <iostream>
#include <string.h>

using namespace std;

int k;

char parenthesis[10];
int visited[10];
char curN[11];
char minN[11];
char maxN[11];

//long long int minN= 9876543210, maxN=0;

int cmpStr(char *strA, char *strB, int len){
	for (int i=0;i<len;i++)
	{
		if ( strA[i] > strB[i] ) return 1;
		else if ( strA[i] < strB[i] ) return 0;
	}
}

int dfs(int n, int len)
{	
	int sn, en;
	int selected=0;

	if (len>k) 
	{
		curN[len] = '\0';
		
		if ( cmpStr(curN,maxN, len) ) strcpy(maxN,curN);
		if ( cmpStr(minN,curN, len) ) strcpy(minN,curN);
		
		return 0;
	}
		
	if (len==0)
	{
		sn=0;
		en=9;
	} else if (len>0 && parenthesis[len-1]=='>'){
		en = n-1;
		if (en<0) en=0;
		sn = 0;		
	} else if (len>0 && parenthesis[len-1]=='<'){
		sn = n+1;
		if (sn>9) sn=9;
		en = 9;
	}
	
	for (int i=sn;i<=en;i++)
	{
		if ( visited[i] != 1)
		{
			visited[i] = 1;
			selected=1;

			curN[len] = i+'0';
			dfs(i, len+1);
			curN[len] = '\0';

			visited[i] = 0;		
		}
	}
	
	if (selected==0) {
		return 0;
	}
	
}

int main()
{
	char in;
	cin >> k;
	
	memset(minN, '9', 10);
	minN[11] = '\0';
	memset(maxN, '0', 10);
	maxN[11] = '\0';
		
	for (int i=0;i<k;i++)
	{
		cin >> parenthesis[i];	
	}

	dfs(0,0);
	
	cout << maxN << "\n" << minN << "\n";
	return 0;
}
