// https://www.acmicpc.net/problem/9465

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, n;
    cin >> T;

    while (T--) {
        cin >> n;
        int arr1[100001], arr2[100001], dp[100001][3];
        for (int i = 1; i <= n; i++) cin >> arr1[i];
        for (int i = 1; i <= n; i++) cin >> arr2[i];
        dp[1][1] = arr1[1];
        dp[1][2] = arr2[1];
        dp[2][1] = arr1[2] + arr2[1];
        dp[2][2] = arr2[2] + arr1[1];

        for (int i = 3; i <= n; i++) {
            dp[i][1] = max(dp[i - 2][2], dp[i - 1][2]) + arr1[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 2][1]) + arr2[i];
        }

        cout << max(dp[n][1], dp[n][2]) << '\n';
    }

    return 0;
}

/*
  숫자가 더해지는 경우의 수를 확인해보면 dp 점화식을 세울 수 있다!
*/