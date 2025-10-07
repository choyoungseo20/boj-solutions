#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> adj[100001]; // 인접 리스트
priority_queue<pair<int, int>> pq;
int max_weight[100001];

// 다익스트라
void dijkstra(int s) {
    // 시작 섬의 최대 중량 설정
	max_weight[s] = 1234567890;
	pq.push({ 1234567890, s });

	while (!pq.empty()) {
		int w = pq.top().first; // 중량
		int x = pq.top().second; // 섬의 번호
		pq.pop();

        // 현재 섬까지 옮길 수 있는 최대 중량이 현재 중량보다 클 경우
		if (max_weight[x] > w) continue;

        // 현재 섬과 연결되어 있는 모든 섬
		for (int i = 0; i < adj[x].size(); i++) {
            // 현재까지의 중량 & 이동할 다리의 중량 한계의 최솟값이 이동할 수 있는 중량
			int nw = min(adj[x][i].second, w); 
			int nx = adj[x][i].first;

            // 이동할 수 있는 중량이 해당 섬의 최대 중량보다 클 경우
			if (nw > max_weight[nx]) {
				max_weight[nx] = nw;
				pq.push({ nw, nx });
			}
		}
	}
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;

		adj[A].push_back({ B, C });
		adj[B].push_back({ A, C });
	}

	int s, e;
	cin >> s >> e;

	dijkstra(s);

	cout << max_weight[e];
}