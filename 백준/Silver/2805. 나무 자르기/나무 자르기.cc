#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	sort(v.begin(), v.end());

	int idx = 1;
	for (int i = 1; i <= n; i++) {
		sum -= 1LL * (v[i] - v[i - 1]) * (n - i + 1);
		if (m > sum) {
			idx = i;
			break;
		}
	}
	
	int dist = (m - sum) / (n - idx + 1);
	if ((m - sum) % (n - idx + 1) != 0) dist++;

	cout << v[idx] - dist;
}