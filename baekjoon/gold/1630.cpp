// https://www.acmicpc.net/problem/1630

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long p[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    memset(p, 0, sizeof(p));

    p[1] = 1;

    for (long long i = 2; i <= 1000000; i++) {
        if (p[i] != 0) continue;

        p[i] = i;
        for (long long j = i + i; j <= 1000000; j += i) {
            p[j] = 1;
        }
        for (long long j = i * i; j <= 1000000; j *= i) {
            p[j] = i;
        }
    }

    long long res = 1;

    for (int i = 2; i <= N; i++) {
        res = (res * p[i]) % 987654321;
    }

    cout << res;

    return 0;
}

/*
  미리 곱할 수를 저장해놓고 O(N)으로 해결 가능

  결국 소수의 곱이기 때문에 미리 곱할 수를 알아낼 수 있다.
*/