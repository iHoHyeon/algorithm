// https://www.acmicpc.net/problem/11054

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, res = 0;
    cin >> N;

    int dp[1001][3];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        cin >> dp[i][0];
        for (int j = 1; j < i; j++) {
            if (dp[j][0] < dp[i][0]) dp[i][1] = max(dp[i][1], dp[j][1]);
        }
        dp[i][1]++;
    }

    for (int i = N; i >= 1; i--) {
        for (int j = N; j > i; j--) {
            if (dp[j][0] < dp[i][0]) dp[i][2] = max(dp[i][2], dp[j][2]);
        }
        dp[i][2]++;
        res = max(res, dp[i][1] + dp[i][2] - 1);
    }

    cout << res;

    return 0;
}

/*
  가장 긴 증가하는 & 감소하는 부분 수열을 dp에 저장하면서 최댓값을 갱신한다.
*/