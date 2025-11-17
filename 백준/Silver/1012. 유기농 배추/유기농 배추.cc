#include <iostream>
#include <cstring>

using namespace std;

int M, N;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool baechu[51][51] = {false};
bool check[51][51] = {false};

void dfs(int x, int y) {
    check[x][y] = true;
    
    for (int i = 0; i < 4; i++) {
        int m_x = x + dx[i];
        int m_y = y + dy[i];
        
        if (m_x < 0 || m_y < 0 || m_x >= N || m_y >= M) continue;
        if (check[m_x][m_y] == false && baechu[m_x][m_y] == true) dfs(m_x, m_y);
    }
}

int main() {
    int T, K, X, Y;
    
    cin >> T;
    
    while (T--) {
        cin >> M >> N >> K;
        
        for (int i = 0; i < K; i++) {
            cin >> X >> Y;
            baechu[Y][X] = true;
        }
        
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (check[i][j] == false && baechu[i][j] == true) {
                    dfs(i, j);
                    count++;
                }
            }
        }
        
        cout << count << "\n";
        
        memset(baechu, false, sizeof(baechu));
        memset(check, false, sizeof(check));
    }
}