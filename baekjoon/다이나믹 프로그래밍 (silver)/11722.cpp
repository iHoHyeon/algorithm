// https://www.acmicpc.net/problem/11722

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A[1001], dp[1001], res = 1;
    fill_n(dp, 1001, 0);
    cin >> N;
    cin >> A[1];
    dp[1] = 1;

    for (int i = 2; i <= N; i++) {
        cin >> A[i];

        for (int j = 1; j < i; j++) {
            if (A[j] > A[i]) dp[i] = max(dp[j], dp[i]);
        }
        dp[i]++;
        res = max(res, dp[i]);
    }

    cout << res;

    return 0;
}

/*
  수열 A를 입력 받으면서 이전의 최대 감소 수열의 dp를 저장해놓는다.
*/