#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;

    vector<char> V(C);
    for (int i = 0; i < C; i++) {
        cin >> V[i];
    }

    sort(V.begin(), V.end());

    vector<int> mask(C, 1);
    for (int i = 0; i < L; i++) {
        mask[i] = 0;
    }

    do {
        vector<char> ans;
        int vowels = 0;
        int consonants = 0;
        for (int i = 0; i < C; i++) {
            if (!mask[i]) {
                if (V[i] == 'a' || V[i] == 'e' || V[i] == 'i' || V[i] == 'o' || V[i] == 'u') vowels++;
                else consonants++;
                ans.push_back(V[i]);
            }
        }
        if (vowels >= 1 && consonants >= 2) {
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i];
            }
            cout << "\n";
        }
        
    } while (next_permutation(mask.begin(), mask.end()));
}