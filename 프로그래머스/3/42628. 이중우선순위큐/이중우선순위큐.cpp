#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;
    unordered_map<int, int> um;
    
    for (auto op : operations) {
        char o = op[0];
        int num = stoi(op.substr(2));
        if (o == 'I') {
            max_pq.push(num);
            min_pq.push(num);
            um[num]++;
        }
        else {
            if (max_pq.empty() || min_pq.empty()) continue;
            
            if (num == 1) {
                while (!max_pq.empty() && !um[max_pq.top()]) {
                    max_pq.pop();
                }
                if (max_pq.empty()) continue;
                um[max_pq.top()]--;
                max_pq.pop();
                while (!max_pq.empty() && !um[max_pq.top()]) {
                    max_pq.pop();
                }
            }
            else {
                while (!min_pq.empty() && !um[min_pq.top()]) {
                    min_pq.pop();
                }
                if (min_pq.empty()) continue;
                um[min_pq.top()]--;
                min_pq.pop();
                while (!min_pq.empty() && !um[min_pq.top()]) {
                    min_pq.pop();
                }
            }
        }
        
        while (!max_pq.empty() && !um[max_pq.top()]) {
            max_pq.pop();
        }
        while (!min_pq.empty() && !um[min_pq.top()]) {
            min_pq.pop();
        }
    }
    if (max_pq.empty() || min_pq.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }
    
    return answer;
}