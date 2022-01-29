// https://www.acmicpc.net/problem/10090

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long tree[2111111], arr[1000111];
vector<pair<long long, long long>> v;

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
        if (idx == s) tree[N] += val;
        return;
    }

    long long mid = (s + e) / 2;
    update(N * 2, s, mid, idx, val);
    update(N * 2 + 1, mid + 1, e, idx, val);
    tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
    return a.first > b.first;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long temp;
        cin >> temp;
        v.push_back({temp, i});
    }

    sort(v.begin(), v.end(), cmp);
    long long ans = 0;

    for (auto nxt : v) {
        ans += query(1, 1, n, 0, nxt.second);
        update(1, 1, n, nxt.second, 1);
    }

    cout << ans;

    return 0;
}
