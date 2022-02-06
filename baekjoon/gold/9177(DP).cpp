// https://www.acmicpc.net/problem/16474

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int dp[201][201];
string a, b, c;

int solve(int idxA, int idxB, int idxC) {
    if (idxC == c.size()) return 1;

    if (dp[idxA][idxB] != -1) return dp[idxA][idxB];
    dp[idxA][idxB] = 0;

    if (idxA < a.length() and a[idxA] == c[idxC]) dp[idxA][idxB] = solve(idxA + 1, idxB, idxC + 1);
    if (idxB < b.length() and b[idxB] == c[idxC]) dp[idxA][idxB] = max(dp[idxA][idxB], solve(idxA, idxB + 1, idxC + 1));

    return dp[idxA][idxB];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> a >> b >> c;
        memset(dp, -1, sizeof(dp));

        cout << "Data set " << i << ": ";
        if (solve(0, 0, 0))
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }

    return 0;
}

/*

*/