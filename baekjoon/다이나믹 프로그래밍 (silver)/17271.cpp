// https://www.acmicpc.net/problem/17271

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[10001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int B = 0;

    memset(dp, -1, sizeof(dp));
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1];
        if (i - M >= 0) dp[i] = (dp[i] + dp[i - M]) % 1000000007;
    }

    cout << dp[N];

    return 0;
}
/*
  A,B로 N초를 만드는 방법은 N-1초를 만드는 방법과 N-M초를 만드는 방법의 합이다.

  dp[N] = dp[N-1] + dp[N-M]
*/