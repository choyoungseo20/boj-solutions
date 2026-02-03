#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1234567890;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		a[i + 1] = INF;
	}

	int ans = 0;
	a[0] = -INF;
	vector<pair<int, int>> log;
	for (int i = 0; i < v.size(); i++) {
		int l = 0;
		int r = ans;

		while (l <= r) {
			int mid = (l + r) / 2;

			if (v[i] > a[mid]) {
				if (a[mid + 1] > v[i]) {
					log.push_back({ mid + 1, v[i] });
					a[mid + 1] = v[i];
				}
				ans = max(ans, mid + 1);
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	}

	vector<int> arr;
	int idx = ans;
	for (int i = log.size() - 1; i >= 0; i--) {
		if (idx == 0) break;
		if (idx != log[i].first) continue;

		arr.push_back(log[i].second);
		idx--;
	}

	cout << ans << "\n";
	for (int i = ans - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
}