// https://www.acmicpc.net/problem/2294

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k, coins[101], dp[10001];
    fill_n(dp + 1, 10000, 999999);
    dp[0] = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) cin >> coins[i];

    for (int i = 1; i <= n; i++) {
        for (int j = coins[i]; j <= k; j++) {
            dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    int res = dp[k] == 999999 ? -1 : dp[k];
    cout << res;

    return 0;
}

/*
  j를 만드는 경우의 수는 j - (코인 가치)를 만드는 경우의 수 + 1 이다. 
  dp[0] = 0 을 이용해서 모든 경우의 수를 기록할 수 있다.
*/