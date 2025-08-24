#include <iostream>

using namespace std;

int n, m;

// 플러드필
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

int map[501][501];
bool visited[501][501];

int count = 0;
int p_size = 0;
int p_max_size = 0;

// 연결된 모든 그림을 visited로 바꾸는 DFS
void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        
        if (0 < nr && nr <= n && 0 < nc && nc <= m) {
            // 방문하지 않았고, 그림일 경우
            if (!visited[nr][nc] && map[nr][nc] != 0) {
                p_size++; // 그림의 크기 증가
                visited[nr][nc] = true;
                dfs(nr, nc);
            }
        }  
    }   
}

int main() {
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {  
            // 방문하지 않았고, 그림일 경우 
            if (!visited[i][j] && map[i][j] != 0) {
                p_size = 1; // 그림의 크기 초기화
                visited[i][j] = true;
                dfs(i, j);

                count++;
                p_max_size = max(p_max_size, p_size); 
            }
        }
    }
    
    cout << count << "\n";
    cout << p_max_size << "\n";
}