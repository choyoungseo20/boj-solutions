#include <string>
#include <vector>

using namespace std;

bool is_possible(long long n, vector<int>& times, long long total_time) {
    for (int i = 0; i < times.size(); i++) {
        long long cnt = total_time / (1LL * times[i]);
        n -= cnt;
        if (n <= 0) return true;
    }
    
    return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 1000000000000000000;
    
    long long left = 0;
    long long right = 1000000000000000000;
    long long mid;
    while (left < right) {
        mid = (left + right) / 2;
        
        if (is_possible(1LL * n, times, mid)) {
            right = mid;
            answer = min(answer, mid);
        }
        else {
            left = mid + 1;
        }
    }
    
    return answer;
}