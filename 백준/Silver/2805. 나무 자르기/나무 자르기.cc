#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	int max_tree = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		max_tree = max(max_tree, v[i]);
	}

	int l = 0;
	int r = max_tree;
	int ans = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		long long tmp = 0;
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) {
				tmp += v[i] - mid;
				if (tmp >= m) break;
			}
		}
		if (tmp >= m) {
			ans = max(ans, mid);
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << ans;
}