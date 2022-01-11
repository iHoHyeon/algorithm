// https://www.acmicpc.net/problem/1707

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> graph[20001];
int info[20001];

bool dfs(int node, int nowInfo) {
    info[node] = nowInfo;

    bool res = true;
    for (auto i : graph[node]) {
        if (info[i] != 0) {
            if (info[i] == nowInfo) return false;
        } else {
            res = dfs(i, nowInfo * -1);
        }
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, V, E;
    cin >> K;

    while (K--) {
        cin >> V >> E;

        memset(info, 0, sizeof(info));
        for (int i = 1; i <= V; i++) graph[i].clear();

        int temp1, temp2;
        while (E--) {
            cin >> temp1 >> temp2;

            graph[temp1].push_back(temp2);
            graph[temp2].push_back(temp1);
        }

        int nowInfo = 1;
        bool flag = true;

        for (int i = 1; i <= V; i++) {
            if (graph[i].empty() || info[i] != 0) continue;

            flag = dfs(i, nowInfo);

            if (!flag) break;
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}

/*
*/