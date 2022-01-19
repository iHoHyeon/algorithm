// https://www.acmicpc.net/problem/2073

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
int dp[100001];
int temp[100001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D, P;
    cin >> D >> P;

    memset(dp, 0, sizeof(dp));
    memset(temp, 0, sizeof(temp));

    int L, C;

    while (P--) {
        cin >> L >> C;
        v.push_back(make_pair(L, C));
    }

    sort(v.begin(), v.end());

    for (auto i : v) {
        dp[i.first] = max(dp[i.first], i.second);
        for (int now = i.first + 1; now <= D; now++) {
            if (temp[now - i.first] == 0) continue;
            dp[now] = max(min(temp[now - i.first], i.second), dp[now]);
        }

        for (int j = 1; j <= D; j++) temp[j] = dp[j];
    }

    cout << dp[D];

    return 0;
}

/*

*/