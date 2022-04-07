#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector< vector<int> > v;

int main()
{
	string str;
	vector<int> ret;
	char pre=0;
	int H,W;
	
	cin >> H >> W;
	
	for (int i=0;i<H;i++)
	{
		str = {};
		cin >> str;
		pre =0;
		
		for (int j=0;j<str.length();j++)
		{
			if ( str[j]=='.') 
			{
				if ( pre != -1 ) ret[j] = pre + 1;
				else ret[j] = -1;	
			}
			else if ( str[j]=='c') ret[j]=0;
			
			pre = ret[j];	
		}	
		v.push_back(ret);
	}	

	for (auto a : v){
		for (auto b : a )cout << b << " ";
		cout << "\n";
	}
	
	return 0;
}

