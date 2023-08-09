//4 sliced area compression

#include <iostream>
#include <vector>

using namespace std;

vector<char> result;
int a[65][65];

string compress(int sx, int sy, int k)
{
	string a00, a01, a10, a11;
	if (k==1){
		if ( a[sx][sy]==1) return "1";
		else return "0";
	} 
	
 //partition 1
 	a00 = compress (sx,sy, k/2);
 //partition 2
 	a01 = compress (sx,sy+k/2, k/2);
 //partition 3
 	a10 = compress (sx+k/2,sy, k/2);
 //partition 4
	a11 = compress (sx+k/2,sy+k/2, k/2);
	
	if ( a00=="1" && a01=="1" && a10=="1" && a11 == "1" ) return "1";
	else if ( a00=="0" && a01=="0" && a10=="0" && a11 == "0" ) return "0";
	else {
		return "("+a00+a01+a10+a11+")";
	}
	
}

int main()
{
	int size;
	
	cin >> size;
	for (int i=0;i<size;i++)
	{
		for (int j=0;j<size;j++)
		{
			scanf("%1d", &a[i][j]);		//Good tip
		}	
	}
	
	cout << compress(0,0,size);
	
	return 0;
}
