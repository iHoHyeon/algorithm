// https://www.acmicpc.net/problem/1495

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int N, S, M;
int V[1001];
int dp[101][1001];

int solve(int order, int volume) {
    if (volume > M || volume < 0) return -2;
    if (order == N + 1) return dp[order][volume] = volume;
    if (dp[order][volume] != -1) return dp[order][volume];

    dp[order][volume] = max(solve(order + 1, volume + V[order]), solve(order + 1, volume - V[order]));

    return dp[order][volume];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> S >> M;

    for (int i = 1; i <= N; i++) cin >> V[i];

    memset(dp, -1, sizeof(dp));

    int res = solve(1, S);

    res = (res == -2) ? -1 : res;
    cout << res;

    return 0;
}

/*
  단순 재귀로는 시간초과.. DP 메모이제이션을 적용해야 통과 가능하다.
*/