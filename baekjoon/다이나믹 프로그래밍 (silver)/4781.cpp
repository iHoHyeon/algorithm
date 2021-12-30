// https://www.acmicpc.net/problem/4781

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, c;
pair<int, int> cp[5001];
int dp[10001];
double m, p;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0.00) break;

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++) {
            cin >> c >> p;
            cp[i] = make_pair(c, (int)(p * 100 + 0.5));
        }

        int iM = (int)(m * 100 + 0.5);

        for (int i = 1; i <= n; i++) {
            for (int j = cp[i].second; j <= iM; j++) {
                dp[j] = max(dp[j], dp[j - cp[i].second] + cp[i].first);
            }
        }

        cout << dp[iM] << '\n';
    }

    return 0;
}
/*
  냅색 문제와 유사문제 -> 여러개를 담을 수 있다는 점이 차이점
*/