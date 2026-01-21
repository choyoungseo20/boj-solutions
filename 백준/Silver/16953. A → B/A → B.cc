#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<long long, int> visited;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long a, b;
	cin >> a >> b;

	queue<pair<long long, int>> q;
	q.push({ a, 1 });
	visited[a]++;

	while (!q.empty()) {
		long long x = q.front().first;
		int d = q.front().second;
		q.pop();

		if (x == b) {
			cout << d;
			return 0;
		}

		if (x * 2 <= b && visited[x * 2] == 0) {
			visited[x * 2]++;
			q.push({ x * 2, d + 1 });
		}
		if (x * 10 + 1 <= b && visited[x * 10 + 1] == 0) {
			visited[x * 10 + 1]++;
			q.push({ x * 10 + 1, d + 1 });
		}
	}
	cout << -1;
}