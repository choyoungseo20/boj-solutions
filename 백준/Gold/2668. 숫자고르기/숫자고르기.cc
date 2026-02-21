#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n + 1);
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	for (int i = 1; i <= n; i++) {
		vector<bool> visited(n + 1);

		visited[i] = true;
		int c = i;
		while (1) {
			if (visited[v[c]]) {
				if (v[c] == i) {
					ans.push_back(i);
				}
				break;
			}

			visited[v[c]] = true;
			c = v[c];
		}
	}

	cout << ans.size() << "\n";
	for (auto a : ans) {
		cout << a << "\n";
	}
}