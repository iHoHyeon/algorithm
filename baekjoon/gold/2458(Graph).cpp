// https://www.acmicpc.net/problem/2458

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

int graph[501][501];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    memset(graph, 0, sizeof(graph));

    int a, b;
    while (M--) {
        cin >> a >> b;

        graph[a][b] = -1;
        graph[b][a] = 1;
    }

    for (int mid = 1; mid <= N; mid++) {
        for (int start = 1; start <= N; start++) {
            if (graph[start][mid] == 0) continue;

            for (int end = 1; end <= N; end++) {
                if (graph[start][mid] == 1 and graph[mid][end] == 1)
                    graph[start][end] = 1;
                else if (graph[start][mid] == -1 and graph[mid][end] == -1)
                    graph[start][end] = -1;
            }
        }
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++) {
        bool flag = true;
        for (int j = 1; j <= N; j++) {
            if (i != j and graph[i][j] == 0) {
                flag = false;
                break;
            }
        }
        if (flag) cnt++;
    }

    cout << cnt;

    return 0;
}

/*
  풀로이드-와샬 알고리즘
*/