#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;
	vector<int> v(N);
	vector<int> cnt(1000000);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}

	vector<int> s;
	vector<int> ans(N);
	for (int i = 0; i < N; i++) {
		while (!s.empty() && cnt[v[s[s.size() - 1]]] < cnt[v[i]]) {
			ans[s[s.size() - 1]] = v[i];
			s.pop_back();
		}
		s.push_back(i);
	}

	while (!s.empty()) {
		ans[s[s.size() - 1]] = -1;
		s.pop_back();
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i] << " ";
	}
}