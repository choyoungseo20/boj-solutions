#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> answer;
bool visited[10000];

bool dfs(string c, vector<vector<string>>& tickets, int cnt) {
    answer.push_back(c);
    
    if (cnt == tickets.size()) {
        return true;
    }
    for (int i = 0; i < tickets.size(); i++) {
        if (!visited[i] && tickets[i][0] == c) {
            visited[i] = true;
            
            if (dfs(tickets[i][1], tickets, cnt + 1)) {
                return true;
            }
            
            visited[i] = false;
        }
    }
    
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    dfs("ICN", tickets, 0);
    
    return answer;
}