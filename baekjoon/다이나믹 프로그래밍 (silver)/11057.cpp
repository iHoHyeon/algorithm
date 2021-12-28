// https://www.acmicpc.net/problem/11057

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, res = 0;
    cin >> N;

    int dp[1001][10];

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= N; i++) {
        for (int j = 0; j <= 9; j++) {
            int sum = 0;
            for (int k = j; k >= 0; k--) {
                sum += dp[i - 1][k];
            }
            dp[i][j] = sum % 10007;
        }
    }

    for (int i = 0; i <= 9; i++) res += dp[N][i];

    cout << res % 10007;

    return 0;
}

/*
*/