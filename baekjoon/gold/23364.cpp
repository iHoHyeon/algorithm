// https://www.acmicpc.net/problem/23364

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<int> v2;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        v.push_back({i, temp});
        v2.push_back(temp);
    }

    sort(v.begin(), v.end(), cmp);
    sort(v2.begin(), v2.end());

    for (int i = 0; i < n; i++) {
        for (int j = 2; j <= 4111; j++) {
            int idx = lower_bound(v2.begin() + i + 1, v2.end(), v2[i] * j) - v2.begin();

            if (idx == v.size()) break;
            if (v[idx].second == v[i].second * j) {
                cout << v[i].first << ' ' << v[idx].first;
                return 0;
            }
        }
    }

    return 0;
}

/*
 */