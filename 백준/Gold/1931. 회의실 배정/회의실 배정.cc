#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int s, e;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e, s });
	}

	sort(v.begin(), v.end());

	int ans = 1;
	int end_time = v[0].first;
	for (int i = 1; i < n; i++) {
		if (v[i].second < end_time) continue;;
		ans++;
		end_time = v[i].first;
	}

	cout << ans;
}