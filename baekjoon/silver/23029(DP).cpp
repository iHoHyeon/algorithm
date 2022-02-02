// https://www.acmicpc.net/problem/23029

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int f[100001], dp[2][2][100001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> f[i];

    dp[0][0][1] = f[1];
    dp[0][1][2] = f[1] + f[2] / 2;
    dp[0][0][2] = f[2];

    for (int i = 3; i <= N; i++) {
        dp[0][0][i] = max(dp[0][0][i - 3], max(dp[0][1][i - 3], dp[1][0][i - 3])) + f[i];
        dp[0][1][i] = max(dp[0][0][i - 1], dp[1][0][i - 1]) + f[i] / 2;
        dp[1][0][i] = max(dp[0][0][i - 2], max(dp[0][1][i - 2], dp[1][0][i - 2])) + f[i];
    }

    cout << max(dp[0][0][N], max(dp[0][1][N], dp[1][0][N]));

    return 0;
}