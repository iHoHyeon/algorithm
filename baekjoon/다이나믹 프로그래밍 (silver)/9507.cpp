// https://www.acmicpc.net/problem/9507

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n;
    cin >> t;

    long long dp[68];

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i <= 67; i++) dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];

    while (t--) {
        cin >> n;

        cout << dp[n] << '\n';
    }

    return 0;
}

/*
*/