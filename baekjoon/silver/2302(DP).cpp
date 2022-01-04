// https://www.acmicpc.net/problem/2302

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[41][2];  // idx 0 : VIP 여부 저장, idx 1 : 가짓수 저장

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, temp;
    cin >> N >> M;

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < M; i++) {
        cin >> temp;
        dp[temp][0] = 1;
    }

    dp[1][1] = 1;
    dp[2][1] = (dp[1][0] or dp[2][0]) ? 1 : 2;

    for (int i = 3; i <= N; i++) {
        dp[i][1] = dp[i - 1][1];  // 입장권 그대로

        if (!dp[i][0] and !dp[i - 1][0]) {
            dp[i][1] += dp[i - 2][1];  // 왼쪽사람이랑 바꾸는 경우
        }
    }

    cout << dp[N][1];

    return 0;
}

/*
    dp[i] = dp[i-1] + ((i, i-1 번째 모두 VIP가 아닌 경우) ? dp[i-2] : 0)
*/