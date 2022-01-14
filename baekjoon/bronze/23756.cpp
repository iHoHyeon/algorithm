// https://www.acmicpc.net/problem/23756

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int A[101];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i <= N; i++) cin >> A[i];

    int res = 0;

    for (int i = 0; i < N; i++) {
        int d = abs(A[i + 1] - A[i]);
        res += d >= 180 ? 360 - d : d;
    }

    cout << res;

    return 0;
}

/*
*/