#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    vector<pair<int, pair<int, int>>> v;
    for (int i = 0; i < jobs.size(); i++) {
        v.push_back({jobs[i][0], {jobs[i][1], i}});
    }
    sort(v.begin(), v.end());
    
    priority_queue<pair<int, pair<int, int>>> pq;
    
    int j_size = v.size();
    int j_i = 0;
    int t = 0;
    
    while (j_i < j_size || !pq.empty()) {
        while (j_i < j_size && v[j_i].first <= t) {
            pq.push({-v[j_i].second.first, {-v[j_i].first, -v[j_i].second.second}});
            j_i++;
        }
        
        if (pq.empty()) {
            t++;
            continue;
        }
        
        t += -pq.top().first;
        answer += t + pq.top().second.first;
        pq.pop();
    }
    
    answer /= j_size;
    
    return answer;
}