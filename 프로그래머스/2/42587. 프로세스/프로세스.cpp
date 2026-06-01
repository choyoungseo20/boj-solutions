#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    priority_queue<int> pq;
    vector<pair<int, int>> v;
    
    for (int i = 0; i < priorities.size(); i++) {
        pq.push(priorities[i]);
        v.push_back({priorities[i], i});
    }
    
    int rnk = 1;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == pq.top()) {
            pq.pop();
            if (location == v[i].second) answer = rnk;
            rnk++;
        }
        else {
            v.push_back(v[i]);
        }
    }
    
    return answer;
}