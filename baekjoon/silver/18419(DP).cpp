// https://www.acmicpc.net/problem/18419

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dp[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    fill_n(dp, 1000001, 1);

    for (int i = 1; i <= 1000000; i++) {
        int temp = i;
        int sum = 0;

        while (temp > 0) {
            sum += temp % 10;
            temp /= 10;
        }

        if (i + sum > 1000000) continue;
        dp[i + sum] += dp[i];
    }

    cout << dp[N];

    return 0;
}

/*
*/