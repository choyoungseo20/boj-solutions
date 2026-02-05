#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x;
	int y;
};

int ccw(Point a, Point b, Point c) {
	long long value = 1LL * (b.x - a.x) * (c.y - a.y) - 1LL * (b.y - a.y) * (c.x - a.x);

	if (value > 0) return 1;
	else if (value == 0) return 0;
	else return -1;
}

long long find_dist(Point a, Point b) {
	return 1LL * (b.x - a.x) * (b.x - a.x) + 1LL * (b.y - a.y) * (b.y - a.y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<Point> v(4);
	cin >> v[0].x >> v[0].y >> v[1].x >> v[1].y >> v[2].x >> v[2].y >> v[3].x >> v[3].y;

	int res1 = ccw(v[0], v[1], v[2]);
	int res2 = ccw(v[0], v[1], v[3]);
	int res3 = ccw(v[2], v[3], v[0]);
	int res4 = ccw(v[2], v[3], v[1]);

	if (res1 == 0 && res2 == 0 && res3 == 0 && res4 == 0) {
		long long d = find_dist({0, 0}, { abs(v[1].x - v[0].x) + abs(v[3].x - v[2].x), abs(v[1].y - v[0].y) + abs(v[3].y - v[2].y) });
		
		long long max_d = d;

		for (int i = 0; i <= 1; i++) {
			for (int j = 2; j <= 3; j++) {
				max_d = max(max_d, find_dist(v[i], v[j]));
			}
		}

		if (max_d <= d) cout << 1;
		else cout << 0;
	}
	else if (res1 * res2 != 1 && res3 * res4 != 1) {
		cout << 1;
	}
	else cout << 0;
}