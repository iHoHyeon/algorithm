// https://www.acmicpc.net/problem/1222

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

long long A[2000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    memset(A, 0, sizeof(A));

    int temp;
    while (N--) {
        cin >> temp;
        A[temp]++;
    }

    long long res = 0;

    for (int i = 1; i <= 2000000; i++) {
        long long temp = 0;
        for (int j = i; j <= 2000000; j += i) {
            temp += A[j];
        }
        if (temp > 1) res = max(res, temp * i);
    }

    cout << res;

    return 0;
}

/*
*/