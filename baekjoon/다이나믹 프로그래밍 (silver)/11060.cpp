// https://www.acmicpc.net/problem/11060

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int A[1001], dp[1001];
    fill_n(dp, 1001, 2000);
    for (int i = 1; i <= N; i++) cin >> A[i];

    dp[1] = 0;

    for (int i = 1; i <= N; i++) {
        if (A[i] == 0) continue;
        for (int j = i + 1; j <= min(i + A[i], N); j++) dp[j] = min(dp[i] + 1, dp[j]);
    }

    int res = dp[N] == 2000 ? -1 : dp[N];

    cout << res;

    return 0;
}

/*
  각 자리에 도달할 수 있는 최소 경우의 수를 dp에 저장해간다.
*/