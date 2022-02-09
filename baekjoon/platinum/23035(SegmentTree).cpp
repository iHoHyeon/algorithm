// https://www.acmicpc.net/problem/23035

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long tree[400000];
vector<pair<long long, long long>> v;
vector<long long> com_c;

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 0;
    if (l <= s and e <= r) return tree[N];

    long long mid = (s + e) / 2;
    return max(query(N * 2, s, mid, l, r), query(N * 2 + 1, mid + 1, e, l, r));
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
    tree[N] = max(tree[N * 2], tree[N * 2 + 1]);
}

long long getCompression(long long a) {
    return (lower_bound(com_c.begin(), com_c.end(), a) - com_c.begin()) + 1;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N, M;
    cin >> N >> M;

    long long T;
    cin >> T;

    while (T--) {
        long long r, c;
        cin >> r >> c;
        if (r > N or c > M) continue;
        v.push_back({r, c});
        com_c.push_back(c);
    }

    sort(v.begin(), v.end());
    sort(com_c.begin(), com_c.end());
    com_c.erase(unique(com_c.begin(), com_c.end()), com_c.end());
    long long res = 0;

    for (auto i : v) {
        long long idx = getCompression(i.second);
        long long temp = query(1, 1, 100001, 1, idx);

        update(1, 1, 100001, idx, temp + 1);
        res = max(res, temp + 1);
    }

    cout << res;

    return 0;
}