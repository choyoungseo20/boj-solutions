#include <iostream>

using namespace std;

int N, M;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool arr[101][101];
bool check[101][101];

int res;

void flood_fill(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
            if (arr[nx][ny]) {
                if (!check[nx][ny]) {
                    res++;
                    check[nx][ny] = true;
                    flood_fill(nx, ny);
                }
            }
        }
    }

}

int main() {
    int K, r, c;

    cin >> N >> M >> K;

    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        arr[r - 1][c - 1] = true;
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check[i][j] == false && arr[i][j] == true) {
                res = 1;
                check[i][j] = true;
                flood_fill(i, j);
                ans = max(ans, res);
            }
        }
    }

    cout << ans;
}