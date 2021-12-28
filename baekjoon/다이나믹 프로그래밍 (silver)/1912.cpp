// https://www.acmicpc.net/problem/1912

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, res = -1001;
    int dp[100001][2];
    dp[0][1] = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][0];

        dp[i][1] = max(dp[i - 1][1] + dp[i][0], dp[i][0]);
        res = max(res, dp[i][1]);
    }

    cout << res;

    return 0;
}

/*
  매 인덱스를 입력 받으면서 해당 인덱스를 마지막으로 하는 연속합이 최대가 되는 dp를 저장한다.
*/