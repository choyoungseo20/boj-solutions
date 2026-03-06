#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool possible_change(string s1, string s2) {
    int cnt = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) cnt++;
    }
    
    if (cnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    unordered_map<string, bool> um;
    
    queue<pair<int, string>> q;
    q.push({0, begin});
    um[begin] = true;
    
    while (!q.empty()) {
        int dist = q.front().first;
        string str = q.front().second;
        q.pop();
        
        if (str == target) {
            answer = dist;
            break;
        }
        
        for (auto w : words) {
            if (!um[w] && possible_change(str, w)) {
                q.push({dist + 1, w});
                um[w] = true;
            }
        }
    }
    
    return answer;
}