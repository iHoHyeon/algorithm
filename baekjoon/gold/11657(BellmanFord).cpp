// https://www.acmicpc.net/problem/11657

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n;
long long dist[501];
long long INF = 987654321;
vector<pair<int, int>> adj[501];
bool negative_cycle = false;

void bellman_ford(int start) {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    for (int iter = 1; iter <= n; iter++) {
        //모든 정점을 돌면서 최단거리 배열을 갱신하는 횟수
        for (int cur = 1; cur <= n; cur++) {
            for (pair<int, int> E : adj[cur]) {
                int next = E.first, cost = E.second;
                if (dist[cur] != INF and dist[next] > dist[cur] + cost) {
                    // cur가 방문된 정점이고, 현재 경우가 더 최단경로라면 갱신한다
                    dist[next] = dist[cur] + cost;
                    if (iter == n) {
                        // n번째에 갱신된 정점이 있다면, 음수 cycle이 존재한다는 것이다.
                        negative_cycle = true;
                    }
                }
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int M;
    cin >> M;
    while (M--) {
        int A, B, C;
        cin >> A >> B >> C;

        adj[A].push_back({B, C});
    }
    bellman_ford(1);

    if (negative_cycle) {
        cout << -1;
    } else {
        for (int i = 2; i <= n; i++) {
            if (dist[i] == INF) {
                cout << -1 << '\n';
            } else {
                cout << dist[i] << '\n';
            }
        }
    }

    return 0;
}

/*
 */