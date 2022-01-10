// https://www.acmicpc.net/problem/23074

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long p[500001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N;
    cin >> N;

    fill_n(p, 500001, 1);

    long long cnt = 0;

    for (long long i = 2; i <= N; i++) {
        if (p[i] != 1) continue;

        long long now = 2;
        for (long long j = i + i; j <= N; j += i) {
            if (p[j] == 1) {
                p[j] = now++;
            } else {
                if (now <= p[j]) {
                    now = p[j] + 1;
                    continue;
                } else
                    p[j] = now++;
            }
        }

        cnt = max(cnt, now);
    }

    cout << ((N == 1) ? 1 : cnt - 1) << '\n';
    for (long long i = 1; i <= N; i++) cout << p[i] << ' ';

    return 0;
}

/*
  2의 배수가 250,000개
  따라서 2 이상 수의 배수는 항상 2의 배수보다 적다.
  
  => 각 소수의 배수를 순서대로 order를 저장해주다가 이미 저장된 수를 만나면
  그 수는 지금의 소수보다 작은 소수의 배수이다. 
  따라서 order를 갱신해준다.
*/