// https://www.acmicpc.net/problem/23888

#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long a, d, q, l, r;

    cin >> a >> d >> q;

    while (q--) {
        int query;
        cin >> query >> l >> r;
        if (query == 1) {
            long long res = ((2 * a + (r + l - 2) * d) * (r - l + 1)) / 2;
            cout << res << '\n';
        } else {
            if (r == l)
                cout << a + (r - 1) * d << '\n';
            else {
                cout << gcd(a, d) << '\n';
            }
        }
    }

    return 0;
}

/*
  1번 쿼리에서 미리 누적합을 계산해놓는 방법도 있다.

  2번 쿼리는 유클리드 호제법 활용 : gcd(a, b) = gcd(a + c * b, b)
*/