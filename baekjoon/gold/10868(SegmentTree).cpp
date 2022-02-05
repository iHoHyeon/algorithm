// https://www.acmicpc.net/problem/10868

#include <algorithm>
#include <iostream>

using namespace std;

int tree[400000];
int arr[100001];

long long init(long long N, long long s, long long e) {
    if (s == e) {
        return tree[N] = arr[s];
    }

    long long mid = (s + e) / 2;

    return tree[N] = min(init(2 * N, s, mid), init(2 * N + 1, mid + 1, e));
}

long long query(long long N, long long s, long long e, long long l, long long r) {
    if (l > e or r < s) return 1000000001;
    if (l <= s and e <= r) {
        return tree[N];
    }

    long long mid = (s + e) / 2;

    return min(query(2 * N, s, mid, l, r), query(2 * N + 1, mid + 1, e, l, r));
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];
    init(1, 1, N);

    int a, b;
    while (M--) {
        cin >> a >> b;
        cout << query(1, 1, N, a, b) << '\n';
    }

    return 0;
}

/*

*/