// https://www.acmicpc.net/problem/11052

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, P[1001];
    cin >> N;
    P[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        for (int j = 1; j < i; j++) {
            P[i] = max(P[i], P[i - j] + P[j]);
        }
    }

    cout << P[N];

    return 0;
}

/*
  동전 문제와 유사한 문제
  입력을 받으면서 각 개수의 최댓값을 갱신하여 기억한다.
*/