#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int cnt[10001];

int solution(vector<int> citations) {
    int answer = 0;
    
    sort(citations.begin(),citations.end());
    
    int c_size = citations.size();
    for (int i = 0; i < c_size; i++) {
        cnt[citations[i]]++;
    }
    for (int i = citations[0] + 1; i <= citations[c_size - 1]; i++) {
        cnt[i] += cnt[i - 1];
    }
    
    for (int i = 0; i <= citations[c_size - 1]; i++) {
        if (c_size - cnt[i - 1] >= i && i > cnt[i - 1]) answer = i;
    } 
    
    return answer;
}