#include <iostream>
#include <cstring>

using namespace std;

int w, h;

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};

int map[51][51] = {0};
bool check[51][51] = {false};

void dfs(int x, int y) {
    check[x][y] = true;
    
    for (int i = 0; i < 8; i++) {
        int m_x = x + dx[i];
        int m_y = y + dy[i];
        
        if (m_x < 0 || m_y < 0 || m_x >= h || m_y >= w) continue;
        if (check[m_x][m_y] == false && map[m_x][m_y] != 0) dfs(m_x, m_y);
    }
}

int main() {
    while(1) {
        cin >> w >> h;
        
        if (w == 0 && h == 0) break;
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        
        int count = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (check[i][j] == false && map[i][j] != 0) {
                    dfs(i, j);
                    count++;
                }               
            }
        }
        cout << count << "\n";
        
        memset(map, 0, sizeof(map));
        memset(check, false, sizeof(check));
    }
}