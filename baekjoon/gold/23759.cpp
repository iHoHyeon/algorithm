// https://www.acmicpc.net/problem/23759

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[11][26];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    memset(dp, 0, sizeof(dp));

    int res = 0;

    string temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;

        int nowMax = 0;
        for (int j = 1; j <= K; j++) {
            nowMax = max(nowMax, dp[j][temp[j - 1] - 'a'] + 1);
        }

        for (int j = 1; j <= K; j++) {
            dp[j][temp[j - 1] - 'a'] = nowMax;
        }

        res = max(res, nowMax);
    }

    cout << N - res;

    return 0;
}

/*
  dp에 dp[i][j]으로 i번째 문자에 j (알파벳 0 ~ 26)이 오는 최대의 경우의 수를 모두 저장해놓는다.
*/