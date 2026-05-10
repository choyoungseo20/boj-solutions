#include <string>
#include <vector>

using namespace std;

vector<int> adj[101];
bool visited[101];

int dfs(int n, int cnt) {
    for (int i = 0; i < adj[n].size(); i++) {
        int nn = adj[n][i];
        if (visited[nn]) continue;
        
        visited[nn] = true;
        cnt += dfs(nn, 1);
    }
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j <= n; j++) {
            adj[j].clear();
            visited[j] = false;
        }
        
        for (int j = 0; j < n - 1; j++) {
            if (i == j) continue;
            adj[wires[j][0]].push_back(wires[j][1]);
            adj[wires[j][1]].push_back(wires[j][0]);
        }
        
        int cnt[2];
        int k = 0;
        for (int j = 1; j <= n; j++) {
            if (visited[j] || k >= 2) continue;
            
            visited[j] = true;
            cnt[k] = dfs(j, 1);
            k++;
        }
        
        answer = min(answer, abs(cnt[0] - cnt[1]));
    }
    
    return answer;
}