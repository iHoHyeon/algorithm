// https://www.acmicpc.net/problem/18117

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long fmul(long long x, long long y, long long mod) {
    if (y == 0) return 0;
    if (y == 1) return x % mod;
    long long res = fmul(x, y / 2, mod);
    long long temp = (res * 2) % mod;

    if (y % 2 == 0)
        return temp;
    else
        return (temp + x) % mod;
}

long long fpow(long long C, long long n, long long mod) {
    if (n == 0) return 1;
    if (n == 1) return C % mod;

    long long x = fpow(C, n / 2, mod);
    long long temp = fmul(x, x, mod);

    if (n % 2 == 0)
        return temp;
    else
        return fmul(C, temp, mod);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;

    while (T--) {
        long long a, b, i, n;
        cin >> a >> b >> i >> n;
        a = fmul(fpow(10, i - 1, b), a, b);

        for (int j = 0; j < n; j++) {
            cout << (int)(((long double)a / b) * 10);
            a = fmul(10, a, b);
        }
        cout << '\n';
    }

    return 0;
}

/*
  # 분할정복을 이용한 거듭제곱 https://hbj0209.tistory.com/43
    C^n = (n = 짝수) C^(n/2) * C^(n/2)
          (n = 홀수) C^((n-1)/2) * C^((n-1)/2) * C

    위를 참고해 곱셈 분할정복도 구현했다.
*/