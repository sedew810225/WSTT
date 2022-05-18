#include <iostream>
#include <stack>

using namespace std;

int a[1000004];
int ret[1000004];

stack<int> s;
//어떤 기준점으로부터 값을 비교 > stack
 
int main()
{
	
	int cnt;
	int OBN=-1;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> cnt;
	
	for (int i=0;i<cnt;i++)
	{
		cin >> a[i];

		while ( !s.empty() && a[s.top()] < a[i] )
		{
			ret[s.top()] = a[i];
			s.pop();
		}
		s.push(i);
		ret[i]=-1;
	}
	
	for (int i=0;i<cnt;i++)
	{
		cout << ret[i] << " ";
	}
	
	return 0;
}
