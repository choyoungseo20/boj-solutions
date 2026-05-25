#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for (int i = 1; i <= 1000000; i++) {
        if (yellow % i) continue;
        if (i > yellow / i) continue;
        
        int w = i;
        int h = yellow / i;
        
        int sum = 2 * w + 2 * h + 4;
        if (brown == sum) {
            answer.push_back(max(w + 2, h + 2));
            answer.push_back(min(w + 2, h + 2));
        }
    }
    return answer;
}