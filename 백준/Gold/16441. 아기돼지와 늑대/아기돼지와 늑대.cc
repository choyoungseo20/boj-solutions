#include <iostream>
#include <vector>

using namespace std;

char map[101][101];
bool visited[101][101];

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int N, M;

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (0 < nr && nr <= N && 0 < nc && nc <= M) {
            while (map[nr][nc] == '+') {
                int nnr = nr + dr[i];
                int nnc = nc + dc[i];
                if (0 < nnr && nnr <= N && 0 < nnc && nnc <= M) {
                    if (map[nnr][nnc] == '#') break;
                    else {
                        nr = nnr;
                        nc = nnc;
                    }
                }
                else break;
            }
            if (map[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<pair<int, int>> v;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'W') {
                v.push_back({ i, j });
            }
        }
    }
    
    int wolves_cnt = v.size();
    for (int i = 0; i < wolves_cnt; i++) {
        int sr = v[i].first;
        int sc = v[i].second;
        
        if (!visited[sr][sc]) {
            visited[sr][sc] = true;
            dfs(sr, sc);
        }       
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == '.' && !visited[i][j]) {
                cout << "P";
            }
            else cout << map[i][j];
        }
        cout << "\n";
    }
}