#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = nums.size();
    unordered_map<int, bool> um;
    
    for (int n : nums) {
        if (um[n]) {
            answer--;
        }
        um[n] = true;
    }
    
    if (answer > nums.size() / 2) answer = nums.size() / 2;
    
    return answer;
}