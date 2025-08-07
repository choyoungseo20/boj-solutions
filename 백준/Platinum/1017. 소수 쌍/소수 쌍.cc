#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int matching[51]; // 매칭 정보
int parent[51]; // 부모 노드
int color[51]; // color (0: 짝수  / 1: 홀수 / -1: 방문 x)
vector<int> adj[51];

bool notPrime[2001];

int N;

void find_primes() {
    notPrime[0] = true;
    notPrime[1] = true;

    for (int i = 2; i * i <= 2000; i++) {
        if (notPrime[i]) continue;
        for (int j = i * i; j <= 2000; j += i) {
            notPrime[j] = true;
        }
    }
}

// augmenting path를 찾은 후 flip
// root & v: color 0
// u: color 1
void flip_augment(int root, int u) {
    while (parent[u] != root) {
        int v = parent[u], w = matching[v];

        matching[u] = v;
        matching[v] = u;

        matching[w] = 0;
        u = w;
    }
    matching[u] = root;
    matching[root] = u;
}

// augmenting path 찾기
// 이분 매칭, 소수는 무조건 홀수 그룹의 원소 + 짝수 그룹의 원소
int find_augment(int r, int matched) {
    fill(parent, parent + N + 1, 0);
    fill(color, color + N + 1, -1);

    queue<int> q; // BFS, color = 0인 정점

    color[r] = 0;
    q.push(r);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto& v : adj[u]) {
            if (v == 1 || v == matched) continue;
            if (color[v] == -1) {
                parent[v] = u;
                color[v] = 1;

                if (!matching[v]) {
                    flip_augment(r, v);
                    return 1;
                }

                color[matching[v]] = 0;
                q.push(matching[v]);
            }
        }
    }

    return 0;
}

int main() {
    find_primes();

    cin >> N;

    vector<int> V(N + 1);
    vector<int> ans;
\
    for (int i = 1; i <= N; i++) {
        cin >> V[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (!notPrime[V[i] + V[j]]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (auto& i : adj[1]) {
        fill(matching, matching + N + 1, 0);
        int res = 1;
        for (int j = 2; j <= N; j++) {
            if (i == j) continue;
            if (!matching[j]) { // exposed vertex
                if (find_augment(j, i)) {
                    res++; // augmenting path를 찾으면 매칭 쌍 1 증가
                }
            }
        }
        if (N / 2 == res) ans.push_back(V[i]);
    }


    if (ans.size() == 0) cout << -1;
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
}