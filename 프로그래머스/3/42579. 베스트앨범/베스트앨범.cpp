#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, int> um;
    unordered_map<string, vector<pair<int, int>>> gen_plays;
    
    int sing_cnt = genres.size();
    for (int i = 0; i < sing_cnt; i++) {
        um[genres[i]] += plays[i];
        gen_plays[genres[i]].push_back({plays[i], sing_cnt - i});
    }
    
    vector<pair<int, string>> total_plays;
    for (auto tp : um) {
        total_plays.push_back({tp.second, tp.first});
    }
    
    sort(total_plays.begin(), total_plays.end(), greater<pair<int, string>>());
    
    for (int i = 0; i < total_plays.size(); i++) {
        string genre = total_plays[i].second;
        
        vector<pair<int, int>> gen_play = gen_plays[genre];
        sort(gen_play.begin(), gen_play.end(), greater<pair<int, int>>());
        
        int iter = 2;
        if (iter > gen_play.size()) iter = gen_play.size();
        for (int j = 0; j < iter; j++) {
            answer.push_back(-gen_play[j].second + sing_cnt);
        }
    }
    
    return answer;
}