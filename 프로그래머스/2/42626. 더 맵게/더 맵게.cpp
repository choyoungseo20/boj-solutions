#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int> pq;
    
    for (auto s: scoville) {
        pq.push(-s);
    }
    
    int answer = 0;
    while (pq.size() >= 2 && -pq.top() < K) {
        answer++;
        int s1 = -pq.top();
        pq.pop();
        int s2 = -pq.top();
        pq.pop();
        
        pq.push(-(s1 + s2 * 2));
    }
    
    if (-pq.top() < K) answer = -1;
    
    return answer;
}