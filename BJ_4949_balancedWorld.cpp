#include <iostream>
#include <stack>

using namespace std;
stack <char> s;

int main()
{
	char a;
	int result = 1;
	int ending;
	
	do {
		int result = 1;
		ending = 0;
		
		do {
			scanf("%c", &a);
			
			if ( a== '\n' ) continue;
			if ( ending==0 && a=='.') return 0;
			ending = 1;
			
			if ( a== '(' || a=='[') s.push(a);
			else 
			{
				if ( a== ')')
				{
					if ( !s.empty() && s.top() == '(') s.pop();
					else
					{
						result = 0;
					}
					
				} else if ( a== ']') {
					if ( !s.empty() && s.top() == '[') s.pop();
					else
					{
						result = 0;
					}	
				}
			}		
			
		} while ( a != '.' && a != EOF);
		
		if (result!=0) {
				if ( s.empty() ) cout << "yes" << "\n";
				else cout << "no" << "\n";
		} else {
			cout << "no" << "\n";
		}
	
		while (!s.empty()) s.pop();
	
	} while (a!= EOF);
	
	return 0;
}
