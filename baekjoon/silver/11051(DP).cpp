// https://www.acmicpc.net/problem/11051

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[1001][1001];

int combination(int n, int r) {
    if (r == 0) return 1;
    if (r == 1) return n;
    if (n == r) return 1;

    if (dp[n][r] != -1) return dp[n][r];

    return dp[n][r] = (combination(n - 1, r - 1) + combination(n - 1, r)) % 10007;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(dp, -1, sizeof(dp));

    cout << combination(N, K);

    return 0;
}

/*
*/