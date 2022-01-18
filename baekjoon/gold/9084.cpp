// https://www.acmicpc.net/problem/9084

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int coin[21], dp[10001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        memset(dp, 0, sizeof(dp));

        int N;
        cin >> N;

        for (int i = 1; i <= N; i++) cin >> coin[i];

        int M;
        cin >> M;

        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int now = coin[i]; now <= M; now++) {
                dp[now] += dp[now - coin[i]];
            }
        }

        cout << dp[M] << '\n';
    }

    return 0;
}

/*

*/