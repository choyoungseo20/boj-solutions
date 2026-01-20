#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> v(n);
	set<int> s;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		s.insert(v[i]);
	}

	unordered_map<int, int> hash_map;
	int i = 0;
	for (auto cnt : s) {
		hash_map[cnt] = i++;
	}

	for (int i = 0; i < n; i++) {
		cout << hash_map[v[i]] << " ";
	}
}