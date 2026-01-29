#include <iostream>
#include <vector>

using namespace std;

long long ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int x1 = a.first;
	int y1 = a.second;
	int x2 = b.first;
	int y2 = b.second;
	int x3 = c.first;
	int y3 = c.second;

	return 1LL * (x2 - x1) * (y3 - y1) - 1LL * (y2 - y1) * (x3 - x1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	long long ans1 = 0;
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		ans1 += v[i].first * v[j].second + v[i].second * v[j].first;
	}
	ans1 = llabs(ans1);

	long long ans2 = 0;
	for (int i = 1; i < n - 1; i++) {
		ans2 += ccw(v[0], v[i], v[i + 1]);
	}
	ans2 = llabs(ans2);

	if (ans2 % 2 == 0) cout << ans2 / 2 << ".0";
	else cout << ans2 / 2 << ".5";
}