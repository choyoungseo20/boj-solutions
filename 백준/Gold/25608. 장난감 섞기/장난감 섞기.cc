#include <iostream>
#include <algorithm>

using namespace std;

int input[10002];
int info[11][4];
int N, M;
bool visited[11];
int ans = 0;

void back_tracking(int idx, int current_suffix, int current_max) {
	if (idx == N + 1) {
		ans = max(ans, current_max);
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;

			int new_max = max({ current_max, info[i][1], current_suffix + info[i][2] });

			int new_suffix = max(info[i][3], current_suffix + info[i][0]);

			back_tracking(idx + 1, new_suffix, new_max);

			visited[i] = false;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	cin >> N >> M;

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

		info[i][0] = total_sum1;
		info[i][1] = inner_max;
		info[i][2] = prefix_max;
		info[i][3] = suffix_max;
	}

	back_tracking(1, 0, 0);

	cout << ans;
}