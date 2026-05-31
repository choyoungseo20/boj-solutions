#include <string>
#include <vector>

using namespace std;

vector<int> adj[101];
int cnt[101];
bool visited[101];
int rnk[101];

void init() {
    for (int i = 1; i < 101; i++) visited[i] = false;
}

void dfs(int x) {
    for (int i = 0; i < adj[x].size(); i++) {
        if (visited[adj[x][i]]) continue;
        
        visited[adj[x][i]] = true;
        cnt[adj[x][i]]++;
        
        dfs(adj[x][i]);
    }
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    
    for (int i = 0; i < results.size(); i++) {
        adj[results[i][0]].push_back(results[i][1]);
    }
    
    for (int i = 1; i <= n; i++) {
        init();
        
        visited[i] = true;
        cnt[i]++;
        
        dfs(i);
    }
    
    for (int i = 1; i <= n; i++) {
        rnk[cnt[i]]++;
    }
    
    int total_cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (rnk[i] == 1) {
            if (i == total_cnt + rnk[i]) answer++;
        }
        
        total_cnt += rnk[i];
    }
    
    if (rnk[0]) answer = 0;
    
    return answer;
}