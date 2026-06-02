#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int give_up1[5] = {1, 2, 3, 4, 5};
int give_up2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int give_up3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == give_up1[i % 5]) cnt1++;
        if (answers[i] == give_up2[i % 8]) cnt2++;
        if (answers[i] == give_up3[i % 10]) cnt3++;
    }
    
    int max_cnt = max({cnt1, cnt2, cnt3});
    if (max_cnt == cnt1) answer.push_back(1);
    if (max_cnt == cnt2) answer.push_back(2);
    if (max_cnt == cnt3) answer.push_back(3);
    
    return answer;
}