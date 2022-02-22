// https://www.acmicpc.net/problem/11779

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n;
int dist[100005];
int visited[100005];
int pre[100005];
int INF = 987654321;
vector<pair<int, int>> adj[100005];

int dijkstra(int start, int goal) {
    fill_n(dist, 100005, INF);
    fill_n(visited, 100005, 0);
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cur = pq.top().second;
        pq.pop();

        if (visited[cur]) continue;

        visited[cur] = 1;
        for (pair<int, int> u : adj[cur]) {
            int next = u.first, cost = u.second;
            int next_dist = dist[cur] + cost;

            if (dist[next] > next_dist) {
                // 최단거리 갱신
                dist[next] = next_dist;
                pre[next] = cur;
                pq.push({-next_dist, next});
            }
        }
    }

    return dist[goal];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    int m;
    cin >> m;

    while (m--) {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }

    int start, end;
    cin >> start >> end;

    int cost;
    cost = dijkstra(start, end);

    vector<int> res;
    int now = end;
    while (now != start) {
        res.push_back(now);
        now = pre[now];
    }
    res.push_back(start);
    reverse(res.begin(), res.end());

    cout << cost << '\n'
         << res.size() << '\n';
    for (auto i : res) cout << i << ' ';

    return 0;
}

/*
 */