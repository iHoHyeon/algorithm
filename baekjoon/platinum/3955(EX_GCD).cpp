// https://www.acmicpc.net/problem/3955

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
    if (!y) return x;
    return gcd(y, x % y);
}

long long ex_gcd(long long a, long long b) {
    long long r, q, tempA = a, t, t1 = 0, t2 = 1;
    while (b != 0) {
        q = a / b;
        r = a % b;
        t = t1 - q * t2;
        a = b;
        b = r;
        t1 = t2;
        t2 = t;
    }
    while (t1 < 0) t1 += tempA;
    return t1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        long long K, C, x, y;
        cin >> K >> C;

        if (C == 1) {
            if (K == 1000000000)
                cout << "IMPOSSIBLE" << '\n';
            else
                cout << K + 1 << '\n';
            continue;
        } else if (K == 1) {
            cout << 1 << '\n';
            continue;
        } else if (gcd(C, K) != 1) {
            cout << "IMPOSSIBLE" << '\n';
            continue;
        }

        long long res = ex_gcd(K, C);

        if (res > 1000000000)
            cout << "IMPOSSIBLE" << '\n';
        else
            cout << res << '\n';
    }

    return 0;
}

/*
    확장 유클리드 호제법 -> 두 수 a, b에 대해서
    각각 어떤 x, y를 곱하고 더해야 gcd(a, b)가 되는지 알 수 있다.

    ax + by = gcd(a, b) 에서 x, y를 알아내는 알고리즘
*/