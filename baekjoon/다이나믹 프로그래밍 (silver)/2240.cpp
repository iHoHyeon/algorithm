// https://www.acmicpc.net/problem/2240

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int T, W, input[1001], dp[3][1001][31];

int solve(int tree, int time, int move) {
    if (time == T + 1) return 0;
    int& ret = dp[tree][time][move];
    if (ret != -1) return ret;

    if (input[time] == tree) {
        if (move < W)
            return ret = max(solve(tree, time + 1, move) + 1, solve(3 - tree, time + 1, move + 1));
        else
            return ret = solve(tree, time + 1, move) + 1;
    } else {
        if (move < W)
            return ret = max(solve(tree, time + 1, move), solve(3 - tree, time + 1, move + 1) + 1);
        else
            return ret = solve(tree, time + 1, move);
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T >> W;
    for (int i = 1; i <= T; i++) cin >> input[i];
    memset(dp, -1, sizeof(dp));

    cout << solve(1, 1, 0);
    return 0;
}