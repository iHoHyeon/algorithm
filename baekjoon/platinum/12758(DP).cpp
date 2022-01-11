// https://www.acmicpc.net/problem/12758

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[301][333];
vector<int> v[301];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    int mod = 1000000007;

    while (T--) {
        int N;
        cin >> N;

        memset(dp, 0, sizeof(dp));
        for (int i = 0; i <= 300; i++) v[i].clear();

        long long H;
        for (int i = 1; i <= N; i++) {
            cin >> H;

            for (long long j = 1; j * j <= H; j++) {
                if (H % j != 0) continue;
                if (j * j == H)
                    v[i].push_back(j);
                else {
                    v[i].push_back(j);
                    v[i].push_back(H / j);
                }
            }

            sort(v[i].begin(), v[i].end());
        }

        for (int i = 0; i < v[1].size(); i++) {
            dp[1][i] = 1;
        }

        for (int i = 2; i <= N; i++) {
            int nowSize = v[i].size();
            int lastSize = v[i - 1].size();
            for (int j = 0; j < nowSize; j++) {
                for (int k = 0; k < lastSize and v[i - 1][k] <= v[i][j]; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
                }
            }
        }

        int res = 0;

        for (int i = 0; i < 333; i++) res = (res + dp[N][i]) % mod;

        cout << res << '\n';
    }

    return 0;
}

/*
    기존엔 케이스마다 dp테이블 1,000,000개를 모두 순회하며 약수인지, 확인하고 dp를 갱신해주었다.

    시간초과가 발생하였고, 약수의 개수가 최대 sqrt(1,000,000)개 이므로 약수를 크기순으로 저장하여
    비교해주는 방식으로 해결했다.
*/