#include <iostream>
#include <algorithm>

using namespace std;

int input[10002];
int info[11][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	int current_max = 0;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> input[j];
		}

		int total_sum1 = 0;
		int total_sum2 = 0;

		int inner_max = 0;
		int current_sum = 0;

		int prefix_max = 0;
		int suffix_max = 0;
		for (int j = 1; j <= M; j++) {
			total_sum1 += input[j];
			total_sum2 += input[M - j + 1];

			if (current_sum < 0) {
				current_sum = input[j];
			}
			else {
				current_sum += input[j];
			}
			inner_max = max(inner_max, current_sum);

			prefix_max = max(prefix_max, total_sum1);
			suffix_max = max(suffix_max, total_sum2);
		}

		ans = max(ans, inner_max);

		if (total_sum1 > 0) current_max += total_sum1;

		info[i][0] = total_sum1;
		info[i][1] = prefix_max;
		info[i][2] = suffix_max;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) {
				int tmp = info[i][2] + current_max + info[j][1];
				if (info[i][0] > 0) tmp -= info[i][0];
				if (info[j][0] > 0) tmp -= info[j][0];
				
				ans = max(ans, tmp);
			}
		}
	}

	cout << ans;
}