#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<pair<string, int>> v;
    for (int i = 0; i < numbers.size(); i++) {
        string s = to_string(numbers[i]);
        
        while (s.size() < 4) {
            s += s;
        }
        
        s = s.substr(0, 4);
        
        v.push_back({s, numbers[i]});
    }
    
    sort(v.begin(), v.end());
    
    for (int i = v.size() - 1; i >= 0; i--) {
        answer += to_string(v[i].second);
    }
    
    if (answer[0] == '0') answer = "0";
    
    return answer;
}