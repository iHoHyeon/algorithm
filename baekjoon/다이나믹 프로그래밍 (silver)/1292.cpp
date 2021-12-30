// https://www.acmicpc.net/problem/1292

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[1001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;

    int i = 1, n = 1;
    dp[0] = 0;

    while (true) {
        for (int j = 1; j <= i; j++) {
            dp[n] = dp[n - 1] + i;
            n++;
            if (n == 1001) break;
        }
        if (n == 1001) break;
        i++;
    }

    cout << dp[B] - dp[A - 1];

    return 0;
}
/*

*/