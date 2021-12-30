// https://www.acmicpc.net/problem/14501

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int T[16], P[16], dp[17];

    memset(dp, 0, sizeof(dp));

    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];

        dp[i] = max(dp[i], dp[i - 1]);
        dp[i + T[i]] = max(dp[i] + P[i], dp[i + T[i]]);
    }

    cout << max(dp[N], dp[N + 1]);

    return 0;
}
/*
  N번째 일에 상담이 끝나는 경우 -> dp[N+1]에 최댓값 저장
  나머지 경우 -> dp[N]에 저장
*/