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
	long long sum = 3000000001;
	for (int k = 0; k < n - 2; k++) {
		int i = k + 1;
		int j = n - 1;

		while (i < j) {
			long long s = 1LL * v[k] + 1LL * v[i] + 1LL * v[j];

			if (sum > llabs(s)) {
				ans[0] = v[k];
				ans[1] = v[i];
				ans[2] = v[j];

				sum = llabs(s);
			}

			if (s > 0) j--;
			else if (s < 0) i++;
			else {
				cout << v[k] << " " << v[i] << " " << v[j];
				return 0;
			}
		}
	}

	cout << ans[0] << " " << ans[1] << " " << ans[2];
}