#include <vector>
#include <queue>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

bool visited[101][101];

struct Pos {
    int x;
    int y;
    int d;
};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    queue<Pos> q;    
    q.push({0, 0, 1});
    visited[0][0] = true;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int d = q.front().d;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny] || !maps[nx][ny]) continue;
            
            maps[nx][ny] = d + 1;
            q.push({nx, ny, d + 1});
            visited[nx][ny] = true;
        }
    }
    
    answer = maps[n - 1][m - 1];
    if (answer == 1) answer = -1;
    
    return answer;
}