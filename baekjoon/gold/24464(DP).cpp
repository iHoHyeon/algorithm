// https://www.acmicpc.net/problem/24464

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[200001][5];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 4; i++) dp[1][i] = 1;

    long long N;
    cin >> N;

    long long mod = 1000000007;

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= 4; j++) dp[i][0] = (dp[i][0] + dp[i - 1][j]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][4]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][4]) % mod;
        dp[i][3] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
        dp[i][4] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
    }

    long long res = 0;
    for (int j = 0; j <= 4; j++) res = (res + dp[N][j]) % mod;
    cout << res;

    return 0;
}

/*
 */