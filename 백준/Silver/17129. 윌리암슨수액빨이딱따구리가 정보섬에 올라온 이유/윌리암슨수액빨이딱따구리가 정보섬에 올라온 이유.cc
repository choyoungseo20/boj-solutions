#include <iostream>
#include <queue>

using namespace std;

char map[3001][3001];
bool visited[3001][3001];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int main() {
    int n, m;
    cin >> n >> m;

    int ir, ic;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            if (map[i][j] == '2') {
                ir = i;
                ic = j;
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;

    visited[ir][ic] = true;
    q.push({ {ir, ic}, 0 });

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 < nr && nr <= n && 0 < nc && nc <= m) {
                if (!visited[nr][nc]) {
                    if (map[nr][nc] == '1') continue;
                    else if (map[nr][nc] == '0') {
                        visited[nr][nc] = true;
                        q.push({ {nr, nc}, dist + 1 });
                    }
                    else {
                        cout << "TAK" << "\n";
                        cout << dist + 1;
                        return 0;
                    }
                }
            }
        }
    }

    cout << "NIE";
}