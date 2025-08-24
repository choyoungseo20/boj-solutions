#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> cost(N + 1); // 주차 공간의 단위 무게당 요금
    vector<int> weight(M + 1); // 차량들의 무게
    vector<int> parking_pos(M + 1); // 주차된 차량들의 위치
    queue<int> waiting; // 입구에서 대기 중인 차량
    priority_queue<int, vector<int>, greater<int>> pq; // 현재 비어있는 주차 공간의 번호를 오름차순으로 저장

    for (int i = 1; i <= N; i++) {
        cin >> cost[i];
        pq.push(i); // 비어있는 주차 공간 push
    }
    for (int i = 1; i <= M; i++) {
        cin >> weight[i];
    }

    int car;
    int ans = 0;
    for (int i = 0; i < 2 * M; i++) {
        cin >> car;

        if (car > 0) { // 주차장에 들어오는 경우
            if (!pq.empty()) { // 주차 공간이 있는 경우
                int pos = pq.top(); // 현재 비어있는 주차 공간 중 가장 작은 번호
                parking_pos[car] = pos; // 차량이 어디에 주차했는지 저장

                pq.pop(); // 해당 주차 공간을 없앰
            }
            else { // 주차 공간이 없는 경우
                waiting.push(car); // 대기 큐에 저장
            }
        }
        else { // 주차장에서 나가는 경우
            int pos = parking_pos[-car]; // 차량이 주차했었던 위치
            ans += cost[pos] * weight[-car]; // 주차 정산

            pq.push(pos); // 비어있는 주차 공간으로 갱신

            if (!waiting.empty()) { // 대기 중인 차량이 있을 경우
                int waiting_car = waiting.front();

                int pos = pq.top(); // 현재 비어있는 주차 공간 중 가장 작은 번호  
                parking_pos[waiting_car] = pos; // 차량이 어디에 주차했는지 저장

                waiting.pop(); // 대기 중인 차량을 없앰
                pq.pop(); // 해당 주차 공간을 없앰
            }
        }
    }

    cout << ans;
}