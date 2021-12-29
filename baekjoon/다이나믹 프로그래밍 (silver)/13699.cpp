// https://www.acmicpc.net/problem/13699

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {  //
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    long long dp[36];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = 0;
        int j = i;
        while (j-- > 0) {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }

    cout << dp[n];

    return 0;
}

/*

*/