// https://www.acmicpc.net/problem/2156

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int g[10001], dp[10001];
    for (int i = 1; i <= n; i++) cin >> g[i];

    dp[0] = 0;
    dp[1] = g[1];
    dp[2] = g[1] + g[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(g[i] + dp[i - 3] + g[i - 1], max(g[i] + dp[i - 2], dp[i - 1]));
    }

    cout << max(dp[n - 1], dp[n]);

    return 0;
}

/*
  처음에는 dp[i] = max(dp[i-3] + g[i-1], dp[i-2]) + g[i] 라는 점화식만 세웠다.
  이때는 dp[i-1] > dp[i] 인 경우를 체크할 수 없어서 최종적으로 dp[n-1] 과 dp[n] 중에서 더 큰 경우를 정답이라고 생각하였는데

  항상 dp[i]에 i번째까지의 최댓값이 저장되지 않기 때문에 올바르지 않았던 것 같다..

  점화식에 dp[i-1]도 체크하는 식을 세워주어서 해결했다.
*/