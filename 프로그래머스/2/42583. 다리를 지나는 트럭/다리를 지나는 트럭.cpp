#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<pair<int, int>> q;
    int t_i = 0;
    int c_w = 0;
    
    answer++;
    q.push({truck_weights[t_i], 1});
    c_w += truck_weights[t_i];
    t_i++;
    
    
    while (!q.empty()) {
        answer++;
        if (answer - q.front().second >= bridge_length) {
            c_w -= q.front().first;
            q.pop();
        }
        if (t_i < truck_weights.size() && c_w + truck_weights[t_i] <= weight) {
            q.push({truck_weights[t_i], answer});
            c_w += truck_weights[t_i];
            t_i++;
        }
    }
    
    return answer;
}