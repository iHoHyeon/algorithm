// https://www.acmicpc.net/problem/14565

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long gcd(long long x, long long y) {
    if (!y) return x;
    return gcd(y, x % y);
}

// ax + by = 1의 값을 x, y에 저장해주는 함수,
long long ex_gcd(long long a, long long b, long long& x, long long& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    long long ret = ex_gcd(b, a % b, x, y);
    long long temp = y;
    y = x - (a / b) * y;
    x = temp;

    if (x < 0) {
        x += b;
        y -= a;
    }
    return ret;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long A, N;
    cin >> N >> A;

    long long Isum, Imul, y;

    Isum = N - A;
    if (gcd(N, A) != 1)
        Imul = -1;
    else
        ex_gcd(A, N, Imul, y);

    cout << Isum << ' ' << Imul;

    return 0;
}

/*
    곱셈역의 존재 조건은 c가 gcd(a, b)의 배수
    x === 1 (mod b)라면 ax + by = 1 를 만족하는 것, 즉 c = 1이라고 생각할 수 있으므로
    gcd(a, b) = 1이 되어야한다.
*/