// https://www.acmicpc.net/problem/17425

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long acc[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(acc, 0, sizeof(acc));
    for (int i = 1; i <= 1000000; i++) {
        acc[i] += acc[i - 1];
        for (int j = i; j <= 1000000; j += i) {
            acc[j] += i;
        }
    }

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        cout << acc[N] << '\n';
    }

    return 0;
}

/*
  x의 약수 합을 구할 때 x의 약수를 구하는 것이 아니라

  어떤 수를 약수로 갖는 x에 그 약수를 누적으로 더해가는 방식
*/