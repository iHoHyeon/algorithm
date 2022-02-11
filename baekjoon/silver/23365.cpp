// https://www.acmicpc.net/problem/23365

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> d;

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
        d.push_back(temp);
    }

    sort(d.begin(), d.end());

    d.push_back(d[0]);

    long long res = 0;

    for (int i = 0; i < n; i++) {
        res += max(d[i + 1], d[i]);
    }

    cout << res;

    return 0;
}

/*
 */