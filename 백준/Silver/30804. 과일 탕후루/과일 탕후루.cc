#include <iostream>
#include <vector>

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

	// 두 수를 이용한 가장 긴 부분 배열
	int ans = 0;
	int kind[2] = { 0 };
	pair<int, int> cnt[2];
	cnt[0] = { 0, 0 };
	cnt[1] = { 1, 1 };
	int idx = 0;
	for (int i = 0; i < n; i++) {
		if (kind[idx] == v[i]) {
			cnt[idx].first++;
			cnt[idx].second++;
		}
		else {
			idx = (idx + 1) % 2;
			if (kind[idx] == v[i]) {
				cnt[idx].first++;
				cnt[idx].second = 1;
			}
			else {
				ans = max(ans, cnt[0].first + cnt[1].first);
				kind[idx] = v[i];
				cnt[idx] = { 1, 1 };
				cnt[(idx + 1) % 2].first = cnt[(idx + 1) % 2].second;
			}
		}
	}
	ans = max(ans, cnt[0].first + cnt[1].first);
	
	cout << ans;
}