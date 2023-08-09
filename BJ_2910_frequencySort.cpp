#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map <int,int> mp_cnt;	// find best data structure
map <int,int> mp_idx;


// check custom sort for MAP
bool cmp ( const pair<int,int>&a , const pair<int,int>& b)
{
	if (a.second == b.second)
	{
		return mp_idx[a.first] < mp_idx[b.first];
	}
	return a.second > b.second;	
}

int main(){

	int N,C;
	int input;
	int cnt=0;
	
	cin >> N >> C;
	
	for (int i=0;i<N;i++){
		cin >> input;
		
		auto search = mp_cnt.find(input);
		if ( search != mp_cnt.end())
		{
			mp_cnt[search->first]++;
		} else {
			mp_cnt.insert( {input, 1} );
			cnt++;
			mp_idx.insert( {input, cnt});
		}
	}
	
	vector<pair<int, int>> vec_cnt(mp_cnt.begin(), mp_cnt.end());	
	sort ( vec_cnt.begin(), vec_cnt.end(), cmp);
	
	for (auto a : vec_cnt) 
	{
		for (int i=0;i<a.second;i++)
		{
			cout << a.first << " ";
		}
	}
	cout << "\n";
	
	return 0;
}

