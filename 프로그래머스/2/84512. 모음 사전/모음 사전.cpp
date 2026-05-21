#include <string>
#include <vector>

using namespace std;

int cnt;
int answer;

void find_dict(string w, string cw, int idx) {
    if (idx == 6) return;
    string s = "AEIOU";
    
    for (int i = 0; i < 5; i++) {
        cw.push_back(s[i]);
        cnt++;
        if (w == cw) answer = cnt;
        find_dict(w, cw, idx + 1);
        cw.pop_back();
    }
}

int solution(string word) {
    find_dict(word, "", 1);
    return answer;
}