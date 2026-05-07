#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, bool> um;
    for (auto s: phone_book) {
        um[s] = true;
    }
    
    for (auto s: phone_book) {
        for (int i = 0; i < s.size(); i++) {
            if (um[s.substr(0, i)]) answer = false;
        }
    }
    
    return answer;
}