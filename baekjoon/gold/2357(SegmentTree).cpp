// https://www.acmicpc.net/problem/2357

#include <algorithm>
#include <iostream>

using namespace std;

long long arr[100111];
pair<long long, long long> tree[400000];

pair<long long, long long> init(long long N, long long s, long long e) {
    if (s == e)
        return tree[N] = make_pair(arr[s], arr[s]);

    long long mid = (s + e) / 2;
    pair<long long, long long> l_node = init(N * 2, s, mid);
    pair<long long, long long> r_node = init(N * 2 + 1, mid + 1, e);

    return tree[N] = make_pair(min(l_node.first, r_node.first), max(l_node.second, r_node.second));
}

pair<long long, long long> query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return {1111111111, 0};
    if (l <= s and e <= r) return tree[N];

    long long mid = (s + e) / 2;
    pair<long long, long long> l_node = query(N * 2, s, mid, l, r);
    pair<long long, long long> r_node = query(N * 2 + 1, mid + 1, e, l, r);

    return make_pair(min(l_node.first, r_node.first), max(l_node.second, r_node.second));
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);

    while (M--) {
        long long a, b;
        cin >> a >> b;

        pair<long long, long long> res = query(1, 1, N, a, b);

        cout << res.first << ' ' << res.second << '\n';
    }

    return 0;
}
