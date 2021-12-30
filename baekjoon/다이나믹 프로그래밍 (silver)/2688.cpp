// https://www.acmicpc.net/problem/2688

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[65][10];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;

    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            long long sum = 0;
            for (int k = 9; k >= j; k--) {
                sum += dp[i - 1][k];
            }
            dp[i][j] = sum;
        }
    }

    while (T--) {
        int n;
        cin >> n;

        long long res = 0;
        for (int i = 0; i <= 9; i++) res += dp[n][i];

        cout << res << '\n';
    }

    return 0;
}
/*
*/