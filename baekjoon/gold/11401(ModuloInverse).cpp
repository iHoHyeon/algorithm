// https://www.acmicpc.net/problem/11401

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long div_pow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long temp = div_pow(a, b / 2, mod);
    long long res = (temp * temp) % mod;

    return (b % 2 == 0) ? res : (res * a) % mod;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    long long mod = 1000000007;

    long long X = 1, Y = 1;

    for (int i = N - K + 1; i <= N; i++) X = (X * i) % mod;
    for (int i = 1; i <= K; i++) Y = (Y * i) % mod;

    cout << X * div_pow(Y, mod - 2, mod) % mod;

    return 0;
}

/*
*/