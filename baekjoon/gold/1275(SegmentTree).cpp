// https://www.acmicpc.net/problem/1275

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long tree[400000], arr[100001];

long long init(long long N, long long s, long long e) {
    if (s == e) return tree[N] = arr[s];

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

    long long N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, 1, N);

    while (Q--) {
        long long x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);

        cout << query(1, 1, N, x, y) << '\n';
        update(1, 1, N, a, b);
    }

    return 0;
}

/*
 */