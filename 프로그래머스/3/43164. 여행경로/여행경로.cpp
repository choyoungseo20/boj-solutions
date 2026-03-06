#include <string> 
#include <vector> 
#include <unordered_map> 
#include <queue> 
#include <algorithm>

using namespace std; 

vector<string> answer;
unordered_map<string, priority_queue<string, vector<string>, greater<string>>> um; 

void dfs(string c) {
    while (!um[c].empty()) {
        string n = um[c].top();
        um[c].pop();
        dfs(n);
    }
    answer.push_back(c);
}

vector<string> solution(vector<vector<string>> tickets) { 
    for (int i = 0; i < tickets.size(); i++) { 
        um[tickets[i][0]].push(tickets[i][1]); 
    } 
    
    dfs("ICN");
    reverse(answer.begin(), answer.end());
    
    return answer; 
}