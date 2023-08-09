#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//long long number;	// wrong requirement check
string number;	// wrong requirement check
int init=0;

vector<string> m;
string str;

int cmp(string &a, string &b){

	if ( a.size() > b.size() )	return 0;
	else if (a.size()==b.size()) return a < b;	//needs careful design
	else return 1;
	
}

int main()
{

	char a;
	int cnt=0;
	int zero=-1;
	cin >> cnt;
	
	while(cnt--)
	{
		number = {};
		init = 0;
		zero = -1;
		cin >> str;
		
		for (auto a : str)
		{	
			if (  a>='0' && a<='9'){
				if (a=='0' && init==0) {
					zero = 0;	
				} else {
					number.push_back(a);
					init = 1;
					zero = -1;
				}
			} else {		
				if (init !=0 || zero == 0){
					if (zero==0) m.push_back("0");
					else m.push_back(number);
					
					number = {};
					init = 0;
					zero = -1;
				}
			}		
		}
		if (init!=0 || zero==0){	//careful code writing for ending condition
			if (zero==0) m.push_back("0");
			else m.push_back(number);
		}
	}
	
	sort(m.begin(), m.end(), cmp);
	
	for (auto a : m){
		cout << a << "\n";
	}
	
	return 0;
}

