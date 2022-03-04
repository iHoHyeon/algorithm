// https://www.acmicpc.net/problem/24537

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int arr[300001];
int v[1000111];
int cnt[1000111];

int gcd(int x, int y) {
    if (!y) return x;
    return gcd(y, x % y);
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        for (int j = 1; j * j <= arr[i]; j++) {
            if (arr[i] % j == 0) {
                if (v[j])
                    v[j] = gcd(v[j], arr[i]);
                else
                    v[j] = arr[i];
                cnt[j]++;

                if (j * j != arr[i]) {
                    if (v[arr[i] / j])
                        v[arr[i] / j] = gcd(v[arr[i] / j], arr[i]);
                    else
                        v[arr[i] / j] = arr[i];
                    cnt[arr[i] / j]++;
                }
            }
        }
    }

    int Q;
    cin >> Q;

    int K;
    for (int i = 1; i <= Q; i++) {
        cin >> K;

        if (v[K] == K) {
            cout << cnt[K] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }

    return 0;
}

/*
 */