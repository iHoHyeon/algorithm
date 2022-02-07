// https://www.acmicpc.net/problem/1629

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long div_mul(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    if (b == 1) return a % mod;

    long long res = div_mul(a, b / 2, mod);

    return (b % 2 == 0) ? (res * 2) % mod : (((res * 2) % mod) + a) % mod;
}

long long div_pow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    if (b == 1) return a % mod;

    long long temp = div_pow(a, b / 2, mod);
    long long res = div_mul(temp, temp, mod);

    return (b % 2 == 0) ? res : div_mul(res, a, mod);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;

    cout << div_pow(A, B, C);

    return 0;
}

/*
 */