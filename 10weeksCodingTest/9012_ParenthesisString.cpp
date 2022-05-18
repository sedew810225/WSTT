#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main ()
{
	int cnt;
	string str;
	int result=0;
	cin >> cnt;
	
	while (cnt--)
	{
		str = {};
		cin >> str;	
		result = 1;
		
		for (auto a : str)
		{
			if (a=='(')
			{
			//	cout << "+";
				s.push(a);				
			}
			else if (a==')') 
			{
				if (s.empty()) 
				{
					cout << "NO" << "\n";
					result = 0;
					break;	
				}
				else 
				{
				//	cout << "-";
					s.pop();	
				} 
			}			
		}
		
		if (result!=0)
		{
			if (s.empty()) cout << "YES" <<"\n";
			else cout << "NO" << "\n";	
		}
		
		while(!s.empty()){
			s.pop();
		}
		
	}
	
	return 0;
}
