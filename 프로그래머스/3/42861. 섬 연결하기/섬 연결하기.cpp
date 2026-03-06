#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[101];
bool visited[101];

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    for (int i = 0; i < costs.size(); i++) {
        adj[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        adj[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        int c = pq.top().first;
        int x = pq.top().second;      
        pq.pop();
        
        if (visited[x]) continue;
        
        visited[x] = true;
        answer += c;
        
        for (auto nx : adj[x]) {
            if (!visited[nx.first]) {
                pq.push({nx.second, nx.first});
            }
        }
    }
    return answer;
}