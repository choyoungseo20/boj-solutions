#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    
    stack<pair<int, int>> s;
    for (int i = 0; i < prices.size(); i++) {
        int p = prices[i];
        while (!s.empty() && s.top().first > p) {
            answer[s.top().second] = i - s.top().second;
            s.pop();
        }
        
        s.push({p, i});
    }
    
    while (!s.empty()) {
        answer[s.top().second] = prices.size() - 1 - s.top().second;
        s.pop();
    }
    
    
    return answer;
}