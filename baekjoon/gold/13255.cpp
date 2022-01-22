// https://www.acmicpc.net/problem/13255

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int A[1001];
long double dp[1001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= K; i++) cin >> A[i];

    dp[0] = N;

    for (int i = 1; i <= K; i++) {
        dp[i] = dp[i - 1] * (1 - ((long double)A[i] / N)) + (N - dp[i - 1]) * ((long double)A[i] / N);
    }

    cout << fixed;
    cout.precision(15);

    cout << dp[K];

    return 0;
}

/*
*/