#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_x = 1000000001, min_y = 1000000001;

bool start = true;

bool comp(pair<int, int> a, pair<int, int> b) {
	int x1 = min_x;
	int y1 = min_y;
	int x2 = a.first;
	int y2 = a.second;
	int x3 = b.first;
	int y3 = b.second;

	long long value = 1LL * (x1 - x2) * (y1 - y3) - 1LL * (x1 - x3) * (y1 - y2);

	if (value == 0) {
		return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2) < 1LL * (x1 - x3) * (x1 - x3) + 1LL * (y1 - y3) * (y1 - y3);
	}
	else {
		return value > 0;
	}
}

bool comp2(pair<int, int> a, pair<int, int> b) {
	int x1 = min_x;
	int y1 = min_y;
	int x2 = a.first;
	int y2 = a.second;
	int x3 = b.first;
	int y3 = b.second;

	long long value = 1LL * (x1 - x2) * (y1 - y3) - 1LL * (x1 - x3) * (y1 - y2);

	if (value == 0) {
		if (start) return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2) < 1LL * (x1 - x3) * (x1 - x3) + 1LL * (y1 - y3) * (y1 - y3);
		else return 1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2) > 1LL * (x1 - x3) * (x1 - x3) + 1LL * (y1 - y3) * (y1 - y3);
	}
	else {
		start = false;
		return value > 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int x, y;
	char c;
	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> c;
		if (c == 'Y') {
			if (min_x == 1000000001 && min_y == 1000000001) {
				min_x = x;
				min_y = y;
			}
			else if (x < min_x) {
				v.push_back({ min_x, min_y });
				min_x = x;
				min_y = y;
			}
			else if (x == min_x) {
				if (y < min_y) {
					v.push_back({ min_x, min_y });
					min_x = x;
					min_y = y;
				}
				else {
					v.push_back({ x, y });
				}
			}
			else {
				v.push_back({ x, y });
			}
		}
	}

	sort(v.begin(), v.end(), comp);
	sort(v.begin(), v.end(), comp2);

	cout << v.size() + 1 << "\n";
	cout << min_x << " " << min_y << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}
}