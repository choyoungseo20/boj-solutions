#include <iostream>
#include <queue>

using namespace std;

bool visited[100001];
int cnt[100001][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;

	queue<pair<int, int>> q;
	q.push({ n, 0 });
	visited[n] = true;
	cnt[n][0] = 1;

	int t = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int d = q.front().second;

		if (d >= t) t++;

		int p = cnt[x][(t - 1) % 2];
		cnt[x][(t - 1) % 2] = 0;
		q.pop();

		if (x == k) {
			cout << d << "\n";
			cout << p << "\n";
			break;
		}

		if (x - 1 >= 0) {
			if (!visited[x - 1]) {
				cnt[x - 1][t % 2] += p;
				visited[x - 1] = true;
				q.push({ x - 1, d + 1 });
			}
			else if (cnt[x - 1]) cnt[x - 1][t % 2] += p;
		}
		if (x + 1 <= 100000) {
			if (!visited[x + 1]) {
				cnt[x + 1][t % 2] += p;
				visited[x + 1] = true;
				q.push({ x + 1, d + 1 });
			}
			else if (cnt[x + 1]) cnt[x + 1][t % 2] += p;
		}
		if (x * 2 <= 100000) {
			if (!visited[x * 2]) {
				cnt[x * 2][t % 2] += p;
				visited[x * 2] = true;
				q.push({ x * 2, d + 1 });
			}
			else if (cnt[x * 2]) cnt[x * 2][t % 2] += p;
		}
	}
}