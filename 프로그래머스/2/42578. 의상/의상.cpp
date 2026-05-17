#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string, int> um;
    
    for (int i = 0; i < clothes.size(); i++) {
        um[clothes[i][1]]++;
    }
    
    answer = 1;
    for (auto a : um) {
        answer *= a.second + 1;
    }
    answer--;
    
    return answer;
}