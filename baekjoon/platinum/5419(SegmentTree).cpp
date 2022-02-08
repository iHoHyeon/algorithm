// https://www.acmicpc.net/problem/1275

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long tree[400000];
vector<pair<long long, long long>> v;
vector<long long> com_y;

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 0;
    if (l <= s and e <= r) return tree[N];

    long long mid = (s + e) / 2;
    return query(N * 2, s, mid, l, r) + query(N * 2 + 1, mid + 1, e, l, r);
}

void update(long long N, long long s, long long e, long long idx) {
    if (idx > e or idx < s) return;
    if (s == e) {
        if (idx == s) tree[N]++;
        return;
    }

    long long mid = (s + e) / 2;
    update(N * 2, s, mid, idx);
    update(N * 2 + 1, mid + 1, e, idx);
    tree[N] = tree[N * 2] + tree[N * 2 + 1];
}

bool cmp1(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

long long getCompression(long long a) {
    return (lower_bound(com_y.begin(), com_y.end(), a) - com_y.begin());
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long TC;
    cin >> TC;

    while (TC--) {
        long long n;
        cin >> n;
        v.clear();
        com_y.clear();
        memset(tree, 0, sizeof(tree));

        while (n--) {
            long long x, y;
            cin >> x >> y;
            v.push_back({x, y});
            com_y.push_back(y);
        }

        long long res = 0;
        sort(v.begin(), v.end(), cmp1);
        sort(com_y.begin(), com_y.end());
        com_y.erase(unique(com_y.begin(), com_y.end()), com_y.end());

        long long y_size = com_y.size();

        for (int i = 0; i < v.size(); i++) {
            long long x = v[i].first, y = v[i].second;
            long long idx = y_size - getCompression(y);

            res += query(1, 1, 75000, 1, idx);
            update(1, 1, 75000, idx);
        }
        cout << res << '\n';
    }

    return 0;
}

/*
 */