// https://www.acmicpc.net/problem/9343

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long dp[2000001];
vector<int> t, sortedT;

long long div_mul(long long a, long long b, long long mod) {
    if (b == 0) return 0;
    if (b == 1) return a;

    long long res = div_mul(a, b / 2, mod);

    return (b % 2 == 0) ? (res * 2) % mod : (((res * 2) % mod) + a) % mod;
}

long long div_pow(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    if (b == 1) return a;

    long long temp = div_pow(a, b / 2, mod);
    long long res = div_mul(temp, temp, mod);

    return (b % 2 == 0) ? res : div_mul(res, a, mod);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    long long mod = 1000000007;
    memset(dp, 0, sizeof(dp));

    for (int k = 0; k < T; k++) {
        int N;
        cin >> N;

        t.push_back(N);
        sortedT.push_back(N);
    }

    sort(sortedT.begin(), sortedT.end());

    for (int k = 0; k < T; k++) {
        long long X = 1, Y = 1;

        long long Xidx = 0, Yidx = 0;

        for (long long i = 2 * sortedT[k]; i > 0; i--) {
            if (dp[i] != 0) {
                if (Xidx == 0) Xidx = i;
                if (i <= sortedT[k] and Yidx == 0) Yidx = i;
            }
            if (Xidx != 0 and Yidx != 0) break;
        }

        if (Xidx != 0) X = dp[Xidx];
        if (Yidx != 0) Y = dp[Yidx];

        for (long long i = Xidx + 1; i <= 2 * sortedT[k]; i++) {
            X = div_mul(X, i, mod);
        }

        for (long long i = Yidx + 1; i <= sortedT[k]; i++) {
            Y = div_mul(Y, i, mod);
        }

        dp[2 * sortedT[k]] = X;
        dp[sortedT[k]] = Y;
    }

    for (auto now : t) {
        long long X = dp[2 * now];
        long long Y = dp[now];

        Y = div_pow(Y, 2, mod);
        Y = div_mul(Y, now + 1, mod);

        Y = div_pow(Y, mod - 2, mod);

        cout << div_mul(X, Y, mod) << '\n';
    }

    return 0;
}

/*
    페르마 소정리의 활용 (이항 계수) : https://rebro.kr/105

    modulo 나눗셈은 역원의 곱으로 치환할 수 있다!

    시간초과가 발생하여 정렬과 dp 메모이제이션을 추가해서 통과를 받았다.
*/