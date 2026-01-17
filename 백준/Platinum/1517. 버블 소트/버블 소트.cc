#include <iostream>
#include <vector>

using namespace std;

long long ans;

vector<int> merge_sort(vector<int> v) {
	if (v.size() == 1) return v;

	int mid = v.size() / 2;
	vector<int> l = merge_sort(vector<int>(v.begin(), v.begin() + mid));
	vector<int> r = merge_sort(vector<int>(v.begin() + mid, v.end()));

	int i = 0, j = 0;
	vector<int> res;
	res.reserve(l.size() + r.size());
	while (i < l.size() && j < r.size()) {
		if (l[i] > r[j]) {
			res.push_back(r[j]);
			ans += l.size() - i;
			j++;
		}
		else {
			res.push_back(l[i]);
			i++;
		}
	}
	while (i < l.size()) {
		res.push_back(l[i]);
		i++;
	}
	while (j < r.size()) {
		res.push_back(r[j]);
		j++;
	}

	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	vector<int> solve = merge_sort(v);

	cout << ans;
}