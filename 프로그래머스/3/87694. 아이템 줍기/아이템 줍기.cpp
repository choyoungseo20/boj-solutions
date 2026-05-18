#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Point {
    int x;
    int y;
    int d;
};

int map[101][101];
bool visited[101][101];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void draw_map(vector<vector<int>>& rectangle) {
    for (int i = 0; i < rectangle.size(); i++) {
        int w = rectangle[i][2] * 2 - rectangle[i][0] * 2 + 1;
        int h = rectangle[i][3] * 2 - rectangle[i][1] * 2 + 1;
        for (int j = 0; j < w; j++) {
            map[rectangle[i][0] * 2 + j][rectangle[i][1] * 2] = 1;
            map[rectangle[i][0] * 2 + j][rectangle[i][3] * 2] = 1;
        }
        for (int j = 0; j < h; j++) {
            map[rectangle[i][0] * 2][rectangle[i][1] * 2 + j] = 1;
            map[rectangle[i][2] * 2][rectangle[i][1] * 2 + j] = 1;
        }
    }
    for (int i = 0; i < rectangle.size(); i++) {
        for (int j = rectangle[i][0] * 2 + 1; j <= rectangle[i][2] * 2 - 1; j++) {
            for (int k = rectangle[i][1] * 2 + 1; k <= rectangle[i][3] * 2 - 1; k++) {
                map[j][k] = 0;
            }
        }
    }
}

int bfs(int characterX, int characterY, int itemX, int itemY) {
    queue<Point> q;
    q.push({characterX, characterY, 0});
    visited[characterX][characterY] = true;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        
        if (x == itemX && y == itemY) {
            return d / 2;
        }
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx <= 0 || nx > 100 || ny <= 0 || ny > 100) continue;
            if (visited[nx][ny] || !map[nx][ny]) continue;
            
            q.push({nx, ny, d + 1});
            visited[nx][ny] = true;
        }
    }
    return 0;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    draw_map(rectangle);
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer;
}