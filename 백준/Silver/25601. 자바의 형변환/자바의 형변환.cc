#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> hash_map;

bool possible = false;

void dfs(string s1, string s2) {
    if (possible) return;

    auto n = hash_map.find(s1);
    if (n != hash_map.end()) {
        if (n->second == s2) possible = true;
        else dfs(n->second, s2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string child, parent;
    for (int i = 0; i < N - 1; i++) {
        cin >> child >> parent;

        hash_map[child] = parent;
    }

    string s1, s2;
    cin >> s1 >> s2;

    dfs(s1, s2);
    dfs(s2, s1);

    if (possible) cout << 1;
    else cout << 0;
}