#include <iostream>

using namespace std;

char map[101][101];
bool visited[101][101];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int H, W;

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 < nr && nr <= H && 0 < nc && nc <= W) {
            if (!visited[nr][nc] && map[nr][nc] == '#') {
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> H >> W;

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                cin >> map[i][j];
            }
        }

        int ans = 0;
        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                if (!visited[i][j] && map[i][j] == '#') {
                    visited[i][j] = true;
                    dfs(i, j);
                    ans++;
                }
            }
        }

        cout << ans << "\n";

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                map[i][j] = '.';
                visited[i][j] = false;
            }
        }
    }
}