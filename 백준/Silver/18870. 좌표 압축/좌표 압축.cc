#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	vector<int> ans(n);
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back({ x, i });
	}

	sort(v.begin(), v.end());


	int before_x;
	int dup = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			before_x = v[i].first;
		}
		else {
			if (before_x == v[i].first) dup++;
			
			ans[v[i].second] = i - dup;
			before_x = v[i].first;
		}
	}


	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
}