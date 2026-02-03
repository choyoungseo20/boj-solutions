#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans;
int a[1000001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		a[i + 1] = 1234567890;
	}

	a[0] = -1234567890;
	for (int i = 0; i < v.size(); i++) {
		int l = 0;
		int r = ans;

		while (l <= r) {
			int mid = (l + r) / 2;

			if (v[i] > a[mid]) {
				if (a[mid + 1] > v[i]) a[mid + 1] = v[i];
				ans = max(ans, mid + 1);
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
	}

	cout << ans << "\n";
}