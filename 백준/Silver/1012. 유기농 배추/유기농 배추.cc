#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int M, N;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool arr[51][51];
bool check[51][51];

int main() {
    int T, K, X, Y;

    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            arr[Y][X] = true;
        }

        int count = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (check[i][j] == false && arr[i][j] == true) {
                    check[i][j] = true;
                    count++;
                    q.push({ i, j });
                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                                if (arr[nx][ny]) { 
                                    if (!check[nx][ny]) {
                                        check[nx][ny] = true;
                                        q.push({ nx, ny });
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        cout << count << "\n";

        memset(arr, false, sizeof(arr));
        memset(check, false, sizeof(check));
    }
}