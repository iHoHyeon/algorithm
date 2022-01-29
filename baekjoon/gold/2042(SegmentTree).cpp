// https://www.acmicpc.net/problem/2042

#include <algorithm>
#include <iostream>

using namespace std;

long long tree[2111111], arr[1000111];

long long init(long long N, long long s, long long e) {
    if (s == e)
        return tree[N] = arr[s];

    long long mid = (s + e) / 2;
    return tree[N] = init(N * 2, s, mid) + init(N * 2 + 1, mid + 1, e);
}

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 0;
    if (l <= s and e <= r) return tree[N];

    long long mid = (s + e) / 2;
    return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
}

void update(long long N, long long s, long long e, long long idx, long long val) {
    if (idx > e or idx < s) return;
    if (s == e) {
        if (idx == s) tree[N] = val;
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

    long long N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1) {
            update(1, 1, N, b, c);
        } else {
            cout << query(1, 1, N, b, c) << '\n';
        }
    }

    return 0;
}
