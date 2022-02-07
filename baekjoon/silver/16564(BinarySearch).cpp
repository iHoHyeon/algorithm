// https://www.acmicpc.net/problem/2370

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long X[1000001];

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) cin >> X[i];

    long long start = 1, end = 1000000000, ans;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long sum = 0;
        for (long long i = 1; i <= N; i++) {
            if (X[i] < mid) sum += mid - X[i];
        }

        if (sum <= K) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    cout << ans;

    return 0;
}

/*

*/