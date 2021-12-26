// https://www.acmicpc.net/problem/1059

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, n, s, e;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    s = 0;
    e = 1001;

    cin >> L;

    int* set = new int[L];
    for (int i = 0; i < L; i++) cin >> set[i];

    cin >> n;

    while (L--) {
        if (set[L] == n) {
            cout << 0;
            return 0;
        }

        if (set[L] > n) {
            e = min(e, set[L]);
        } else {
            s = max(s, set[L]);
        }
    }

    cout << (n - s) * (e - n) - 1;

    return 0;
}

/*
  입력된 n과 가장 가까운 두 수를 찾아서 O(N)으로 해결 가능

  매번 갱신할 값 s, e의 초기값을 집합 S의 범위 바깥으로 해놓아야한다.
  처음에 s = 1이라고 선언해놓아서 놓친 부분이 있던 문제
*/