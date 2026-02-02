#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	vector<int> ans(3);
	long long sum = 3000000000;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 2; j < n; j++) {
			int l = i + 1;
			int r = j - 1;

			while (l <= r) {
				int mid = (l + r) / 2;

				long long s = 1LL * v[i] + 1LL * v[j] + 1LL * v[mid];

				if (sum > llabs(s)) {
					ans[0] = v[i];
					ans[1] = v[mid];
					ans[2] = v[j];

					sum = llabs(s);
				}

				if (s > 0) {
					r = mid - 1;
				}
				else if (s < 0) {
					l = mid + 1;
				}
				else {
					cout << v[i] << " " << v[mid] << " " << v[j];

					return 0;
				}
			}
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];
}