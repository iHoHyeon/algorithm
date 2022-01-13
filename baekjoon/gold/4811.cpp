// https://www.acmicpc.net/problem/4811

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long dp[61][61];

long long combination(long long a, long long b) {
    if (b == 0) return dp[a][b] = 1;
    if (b == 1) return dp[a][b] = a;
    if (a == b) return dp[a][b] = 1;

    if (dp[a][b] != 0) return dp[a][b];

    return dp[a][b] = combination(a - 1, b - 1) + combination(a - 1, b);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0, sizeof(dp));

    while (true) {
        long long N;
        cin >> N;
        if (N == 0) break;

        cout << combination(2 * N, N) / (N + 1) << '\n';
    }

    return 0;
}

/*
  모든 날짜에서 H의 개수는 W의 개수를 넘을 수 없다.

  => 2N개이므로 (1 / (N+1)) *  2N C N
*/