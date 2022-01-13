// https://www.acmicpc.net/problem/2110

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, C;
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());

    int start = 1;

    int end = v[N - 1] - v[0];

    int res;

    while (start <= end) {
        int mid = (start + end) / 2;

        int lastPos = v[0];
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (v[i] - lastPos >= mid) {
                lastPos = v[i];
                cnt++;
            }
        }

        if (cnt < C) {
            end = mid - 1;
        } else {
            res = mid;
            start = mid + 1;
        }
    }

    cout << res;

    return 0;
}

/*
*/