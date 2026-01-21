#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int x;
	int idx;
	int cnt;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Info> v;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back({ x, i, 0 });
	}

	sort(v.begin(), v.end(),
		[](const Info& a, const Info& b) {
			return a.x < b.x;
		});


	int before_x;
	int dup = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			before_x = v[i].x;
		}
		else {
			if (before_x == v[i].x) dup++;
			
			v[i].cnt = i - dup;
			before_x = v[i].x;
		}
	}


	sort(v.begin(), v.end(),
		[](const Info& a, const Info& b) {
			return a.idx < b.idx;
		});

	for (int i = 0; i < n; i++) {
		cout << v[i].cnt << " ";
	}
}