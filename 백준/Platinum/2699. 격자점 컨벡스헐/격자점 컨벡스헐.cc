#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x;
	int y;
};

Point start;

int ccw(Point p1, Point p2, Point p3) {
	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;
	int x3 = p3.x;
	int y3 = p3.y;

	return (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
}

int dist(Point p1, Point p2) {
	int x1 = p1.x;
	int y1 = p1.y;
	int x2 = p2.x;
	int y2 = p2.y;

	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool comp1(Point a, Point b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y > b.y;
}

bool comp2(Point a, Point b) {
	int value = ccw(start, a, b);
	if (value != 0) return value < 0;
	return dist(start, a) < dist(start, b);
}

vector<Point> find_convex_hull(vector<Point> v) {
	vector<Point> hull;
	hull.push_back(v[0]);
	hull.push_back(v[1]);

	for (int i = 2; i < v.size(); i++) {
		while (hull.size() >= 2) {
			int h_size = hull.size();
			if (ccw(hull[h_size - 2], hull[h_size - 1], v[i]) >= 0) {
				hull.pop_back();
			}
			else break;
		}
		hull.push_back(v[i]);
	}

	return hull;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int p;
	cin >> p;
	
	while (p--) {
		int n;
		cin >> n;

		vector<Point> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i].x >> v[i].y;
		}

		sort(v.begin(), v.end(), comp1);
		start = v[0];

		sort(v.begin() + 1, v.end(), comp2);
		
		vector<Point> ans = find_convex_hull(v);

		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i].x << " " << ans[i].y << "\n";
		}
	}
}