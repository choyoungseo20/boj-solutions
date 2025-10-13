#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	
	vector<int> v(N);
	vector<int> cnt(d + 1, 0);

	cnt[c]++;
	int eat_cnt = 1;
	for (int i = 0; i < N; i++) {
		cin >> v[i];

		if (i < k) {
			if (cnt[v[i]] == 0) {
				eat_cnt++;
			}
			cnt[v[i]]++;
		}
	}

	int ans = eat_cnt;
	int i = 0;
	while (1) {
		if (i >= N) {
			break;
		}

		cnt[v[i]]--;
		if (cnt[v[i]] == 0) eat_cnt--;

		if (cnt[v[(i + k) % N]] == 0) {
			eat_cnt++;
			ans = max(ans, eat_cnt);
		}
		cnt[v[(i + k) % N]]++;
		
		i++;
	}

	cout << ans;
}