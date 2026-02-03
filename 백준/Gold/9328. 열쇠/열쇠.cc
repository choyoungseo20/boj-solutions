#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int h, w;
		cin >> h >> w;

		vector<vector<char>> map(h + 2, vector<char>(w + 2));
		vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));

		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> map[i][j];
			}
		}

		string keys;
		cin >> keys;

		unordered_map<int, bool> hm;
		for (int i = 0; i < keys.size(); i++) {
			hm[keys[i] - 'a'] = true;
		}

		int ans = 0;
		vector<pair<int, int>> wait[26];
		
		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		visited[0][0] = true;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= h + 2 || ny < 0 || ny >= w + 2) continue;
				if (visited[nx][ny] || map[nx][ny] == '*') continue;

				visited[nx][ny] = true;
				if (map[nx][ny] - 'A' >= 0 && map[nx][ny] - 'A' < 26) {
					if (!hm[map[nx][ny] - 'A']) {
						wait[map[nx][ny] - 'A'].push_back({ nx, ny });
						continue;
					}
				}
				if (map[nx][ny] == '$') ans++;
				if (map[nx][ny] - 'a' >= 0 && map[nx][ny] - 'a' < 26) {
					hm[map[nx][ny] - 'a'] = true;

					for (auto a : wait[map[nx][ny] - 'a']) q.push(a);
				}
				
				q.push({ nx, ny });
			}
		}

		cout << ans << "\n";
	}
}