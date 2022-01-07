// https://www.acmicpc.net/problem/6549

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

long long seg[2111111];
long long h[111111];
int n;

int init(int node, int start, int end) {
    if (start == end) return seg[node] = start;
    int mid = (start + end) / 2;

    int l_idx = init(2 * node, start, mid);
    int r_idx = init(2 * node + 1, mid + 1, end);
    return seg[node] = h[l_idx] < h[r_idx] ? l_idx : r_idx;
}

int query(int node, int start, int end, int l, int r) {
    if (end < l or r < start) return -1;
    if (l <= start and end <= r) return seg[node];

    int mid = (start + end) / 2;
    int l_idx = query(2 * node, start, mid, l, r);
    int r_idx = query(2 * node + 1, mid + 1, end, l, r);

    if (l_idx == -1) return r_idx;
    if (r_idx == -1) return l_idx;

    return h[l_idx] < h[r_idx] ? l_idx : r_idx;
}

long long getArea(int left, int right) {
    int idx = query(1, 0, n - 1, left, right);

    long long area = (right - left + 1) * h[idx];

    if (left < idx) {
        long long tempArea = getArea(left, idx - 1);
        area = max(area, tempArea);
    }
    if (idx < right) {
        long long tempArea = getArea(idx + 1, right);
        area = max(area, tempArea);
    }
    return area;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        cin >> n;
        if (n == 0) break;

        for (int i = 0; i < n; i++) cin >> h[i];

        init(1, 0, n - 1);

        cout << getArea(0, n - 1) << '\n';
    }

    return 0;
}

/*
    세그먼트 트리란? https://cocoon1787.tistory.com/313
*/