// https://www.acmicpc.net/problem/10835

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
int N, A[2001], B[2001];
int dp[2001][2001];

int solve(int i, int j) {
    if (i == N + 1 || j == N + 1)
        return 0;

    if (dp[i][j] != -1) return dp[i][j];

    dp[i][j] = 0;

    dp[i][j] = max(solve(i + 1, j), max(solve(i + 1, j + 1), dp[i][j]));
    if (A[i] > B[j]) dp[i][j] = max(solve(i, j + 1) + B[j], dp[i][j]);

    return dp[i][j];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N; i++) cin >> B[i];

    memset(dp, -1, sizeof(dp));
    cout << solve(1, 1);
    return 0;
}
/*
  dp 메모이제이션 + 재귀
*/