#include <iostream>
#include <stack>

using namespace std;

int array[54];
int cnt;
stack<int> st;

int checkLeaf()
{
	bool leaf;
	int result=0;
	
	for (int i=0;i<cnt;i++)
	{
		leaf = true;
		if ( array[i] == -2 ) continue;
		
		for (int j=0;j<cnt;j++)
		{
			if ( array[j]==i ) 
			{
				leaf=false;
				break;
			}
		}
		if ( leaf ) result++;
	}	
	
	return result;
}

void removeNode(int val)
{
	int nextVal;
	
	array[val] = -2;
	
	for (int i=0;i<cnt;i++)
	{
		if (array[i]==val)
		{
			st.push(i);
			array[i] = -2;
		}
	}
	
	if ( !st.empty() )
	{
		nextVal = st.top();
		st.pop();
		removeNode(nextVal);		
	}
	
	return;
}

int main()			// try to use dfs...
{
	int target;
	
	cin >> cnt;
	
	for (int i=0;i<cnt;i++)
	{
		cin >> array[i];
	}
	
	cin >> target;
	
	removeNode(target);
	
	cout << checkLeaf();
	
	return 0;
}
