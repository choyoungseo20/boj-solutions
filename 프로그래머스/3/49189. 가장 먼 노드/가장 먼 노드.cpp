#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[20001];
bool visited[20001];
int dist[20001];
int max_dist = 0;

void bfs(int s) {
    queue<pair<int, int>> q;
    
    q.push({s, 0});
    visited[s] = true;
    dist[s] = 0;
    
    while (!q.empty()) {
        int n = q.front().first;
        int d = q.front().second;
        q.pop();
        
        for (auto nn : adj[n]) {
            if (visited[nn]) continue;
            
            q.push({nn, d + 1});
            visited[nn] = true;
            dist[nn] = d + 1;
            max_dist = max(max_dist, d + 1);
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for (int i = 0; i < edge.size(); i++) {
        adj[edge[i][0]].push_back(edge[i][1]);
        adj[edge[i][1]].push_back(edge[i][0]);
    }
    
    bfs(1);
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == max_dist) {
            answer++;
        }
    }
    
    return answer;
}