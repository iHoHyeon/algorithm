// https://www.acmicpc.net/problem/23760

#include <algorithm>
#include <iostream>

using namespace std;

long long tree[400000];
long long c[100111], w[100001], b[100001];

long long init(long long N, long long s, long long e) {
    if (s == e) {
        return tree[N] = c[s];
    }

    long long mid = (s + e) / 2;

    return tree[N] = init(2 * N, s, mid) + init(2 * N + 1, mid + 1, e);
}

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 0;
    if (l <= s and e <= r) {
        return tree[N];
    }

    long long mid = (s + e) / 2;

    return query(2 * N, s, mid, l, r) + query(2 * N + 1, mid + 1, e, l, r);
}

void update(long long N, long long s, long long e, long long idx, long long val) {
    if (idx > e or idx < s) return;
    if (s == e) {
        if (idx == s) {
            tree[N] += val;
        }
        return;
    }

    long long mid = (s + e) / 2;
    update(N * 2, s, mid, idx, val);
    update(N * 2 + 1, mid + 1, e, idx, val);
    tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        c[num]++;
    }
    init(1, 1, 400000);

    for (int i = 1; i <= M; i++) cin >> w[i];
    for (int i = 1; i <= M; i++) cin >> b[i];

    for (int i = 1; i <= M; i++) {
        long long temp = -1;
        long long start = 1, end = 400000;

        while (start <= end) {
            long long mid = (start + end) / 2;
            long long cnt = query(1, 1, 400000, mid, 400000);  // mid 이상의 개수

            if (cnt >= b[i]) {
                start = mid + 1;
                temp = mid;
            } else {
                end = mid - 1;
            }
        }

        if (temp == -1 or temp < w[i]) {
            cout << 0;
            return 0;
        }

        update(1, 1, N, temp, -1);
        if (temp - w[i] != 0) {
            update(1, 1, N, temp - w[i], 1);
        }
    }

    cout << 1;

    return 0;
}

/*
*/