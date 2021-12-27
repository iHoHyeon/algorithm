// https://www.acmicpc.net/problem/2193

#include <algorithm>
#include <iostream>

using namespace std;
long long N, dp[91], res = 0;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i <= N; i++) dp[i] = dp[i - 1] + dp[i - 2];

    cout << dp[N];
    return 0;
}

/*
  i자리 이친수는 맨 마지막자리가 0인 경우 i-1자리 이친수와 같고, 1인 경우 i-2자리 이친수와 같다.
  따라서 dp[i] = dp[i-2] + dp[i-2];
*/