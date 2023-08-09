#include <iostream>
#include <queue>
using namespace std;

#if 0

int main() {
	queue <int> q;
	queue <int> resultQ;

	int N, K;
	int frontValue = 0;
	int i = 0;

	cin >> N;
	cin >> K;

	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	
	i = 1;
	while (!q.empty()) {
		
		frontValue = q.front();
		q.pop();

		if (i == K) {
			resultQ.push(frontValue);
			i = 0;
		} else q.push(frontValue);

		i++;
	}

	cout << "<";
	while (!resultQ.empty()) {
		cout << resultQ.front();
		resultQ.pop();
		if (resultQ.size() != 0) cout << ", ";
	}
	cout << ">" << endl;

	return 0;
}

#endif