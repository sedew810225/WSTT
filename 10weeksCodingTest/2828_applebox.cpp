// shorted path // BPF
#include <iostream>
#include <queue>
#include <tuple>

#define log 0

using namespace std;

int a[21];
queue < tuple <int,int, int> > q;

int main()
{
	int N, M, J;
	int sum, min=9999999;
	int cur, subSum, head, step;
	
	cin >> N >> M;
	cin >> J;
	
	for (int i=0;i<J;i++)
	{
		cin >> a[i];
	}
	
	// What should be pushed in queue ?
	cur = 0;
	sum=a[cur]-1;
	if ( sum >=0 && sum <= J-1 ) sum=0;
	if (log) cout << "push " << cur << " step " << sum << "\n";
	q.push( make_tuple(cur, 0, sum) );
	
	while (q.size()) 
	{
		tie(cur, head, subSum) = q.front();
		if (cur == J-1) {
			if (log) cout << "result :"<<cur << "," << subSum << "\n";		
			if ( subSum < min ) min = subSum;
		} 
		q.pop();
		if (log) cout << "pop " << cur << " subSum " << subSum << "\n";
		
		if ( a[cur+1]-1 >= head && a[cur+1]-1 <= head+M-1 )
		{
			if (log) cout << "push same " << cur+1 << " step " << subSum << "\n";
			q.push(make_tuple(cur+1, head, subSum));
		} else {
		
			for (int i=a[cur+1]-1-(M-1); i<=a[cur+1]-1 && i <= N-M; i++)
			{ // check correct boundary
				if (i<0 || i>N ) continue;  // check correct boundary
				
				step = i - head;
				if (log) cout << cur << ": from "<<a[cur]<<" to "<< a[cur+1] <<" : " << i << " with " << step <<"\n";
				if (step<0) step = -1*step; // check correct calculation
				if (log) cout << "push " << cur+1 << " step " << subSum+step << "\n";
				q.push( make_tuple(cur+1, i, subSum+step));
			}	
			if (log) cout << "\n";	
		}
	}
	
	//cout << "result :"<<cur << "," << subSum << "\n";		
	if ( subSum < min ) min = subSum;
		 
	cout << min << "\n";
	
	return 0;
}




