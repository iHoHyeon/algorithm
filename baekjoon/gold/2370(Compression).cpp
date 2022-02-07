// https://www.acmicpc.net/problem/2370

#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<int> temp;
int res[20111];
set<int> s;

int getCompression(int a) {
    return 1 + (lower_bound(temp.begin(), temp.end(), a) - temp.begin());
}

int main() {
    // freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r;

        v.push_back({l, r});
        temp.push_back(l);
        temp.push_back(r);
    }
    sort(temp.begin(), temp.end());
    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < v.size(); i++) {
        int l = getCompression(v[i].first);
        int r = getCompression(v[i].second);
        for (int j = l; j <= r; j++) {
            res[j] = i + 1;
        }
    }

    bool flag = false;

    for (int i = 1; i <= temp.size(); i++) {
        if (!flag and res[i] == 0) flag = true;
        s.insert(res[i]);
    }

    int cnt = s.size() - (flag ? 1 : 0);

    cout << cnt;

    return 0;
}

/*
    좌표압축
*/