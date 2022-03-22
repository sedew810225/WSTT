// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	vector<string> buffer;
	string b;
	
	void loop_permutation(string s, vector<int> &check, int level){
	    if (level == s.length() ){
	    	buffer.push_back(b);
	        return;
	    }
	    
	    for (int i=0;i<s.length();i++) {
	        if ( check[i] == 1 ) continue;
	        else {
	            check[i] = 1;
	            b.push_back(s[i]);
	        	loop_permutation(s, check, level+1);
	            check[i] = 0;
	            b.pop_back();
	        }
	    }
	}
	
	vector<string> find_permutation(string S)
	{
	    vector<int> check(S.length()+1);
	    loop_permutation(S, check, 0);
	    sort(buffer.begin(), buffer.end());
	    return buffer;
	}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends
