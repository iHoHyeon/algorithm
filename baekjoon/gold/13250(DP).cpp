// https://www.acmicpc.net/problem/13250

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long double dp[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1] = 1.0;
    dp[2] = dp[1] / 6 + 1;
    dp[3] = (dp[2] + dp[1]) / 6 + 1;
    dp[4] = (dp[3] + dp[2] + dp[1]) / 6 + 1;
    dp[5] = (dp[4] + dp[3] + dp[2] + dp[1]) / 6 + 1;
    dp[6] = (dp[5] + dp[4] + dp[3] + dp[2] + dp[1]) / 6 + 1;

    for (int i = 7; i <= 1000000; i++) {
        for (int j = 1; j <= 6; j++) {
            dp[i] += dp[i - j];
        }
        dp[i] /= 6;
        dp[i] += 1;
    }

    int N;
    cin >> N;

    cout << fixed;
    cout.precision(16);

    cout << dp[N];

    return 0;
}

/*
*/