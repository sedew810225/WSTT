#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> scv;	
int cal[3];
int visited[3];
int power[3] = {9,3,1};

int N;
int MinAtkCnt = 987654321;

int subCombine( vector<int> &st,int size, int vt[3], int tt[3], int len, int level)
{	
	if ( len==size )
	{

		int v[3] = {0,0,0};
		vector<int> s;
		int o[3];
		int subSize=3;
		int temp;
		
		for (int i=0;i<size;i++){
			temp = tt[i]-power[i];
			if ( temp >0 ) s.push_back(temp);
		}
		
		if (s.empty())
		{
			if ( MinAtkCnt > level+1 ) MinAtkCnt = level+1;
			return 0;
		}

		subCombine (s, s.size(), v, o, 0, level+1);
		return 0;		
	}
	
	for (int i=0;i<size;i++)
	{
		if ( vt[i] == 1) continue;
		tt[len] = st[i];			//use correct index
		vt[i] = 1;
		subCombine(st, size, vt, tt, len+1,level);
		vt[i] = 0;
	}
	
	return 0;
}

int main()
{	
	cin.tie(0);
    cout.tie(0);
    
	cin >> N;
	int a;
	
	for (int i=0;i<N;i++)
	{
		cin >> a;
		scv.push_back(a);
	}
	
	subCombine(scv, scv.size(), visited,cal, 0,0);
	cout << MinAtkCnt << "\n";
	return 0;
}
