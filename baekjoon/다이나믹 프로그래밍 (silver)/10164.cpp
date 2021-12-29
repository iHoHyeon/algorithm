// https://www.acmicpc.net/problem/10164

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int dp[16][16];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= 15; i++) {
        dp[i][1] = 1;
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 15; i++) {
        for (int j = 2; j <= 15; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    if (K == 0)
        cout << dp[N][M];
    else {
        int i, j;
        i = (K - 1) / M + 1;
        j = K - M * (i - 1);
        cout << dp[i][j] * dp[N - i + 1][M - j + 1];
    }

    return 0;
}

/*
  미리 dp[N][M] = N*M 사각형을 가로지르는 경우의 수를 저장해놓는다.
  
  K의 행렬 좌표 계산에 유의
*/