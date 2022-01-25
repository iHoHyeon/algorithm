// https://www.acmicpc.net/problem/15681

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[101111];
vector<int> v[101111];

void dfs(int x, int parent) {
    dp[x] = 1;
    for (auto nxt : v[x]) {
        if (nxt == parent) continue;
        dfs(nxt, x);
        dp[x] += dp[nxt];
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, R, Q;
    cin >> N >> R >> Q;

    int U, V;
    for (int i = 0; i < N - 1; i++) {
        cin >> U >> V;
        v[U].push_back(V);
        v[V].push_back(U);
    }

    dfs(R, -1);

    int query;
    while (Q--) {
        cin >> query;
        cout << dp[query] << '\n';
    }

    return 0;
}

/*
*/