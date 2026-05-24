#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> um;
    
    for (auto p: participant) {
        um[p]++;
    }
    for (auto c: completion) {
        um[c]--;
    }
    
    for (auto a: um) {
        if (a.second) {
            answer = a.first;
        }
    }
    
    return answer;
}