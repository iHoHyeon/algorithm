// https://www.acmicpc.net/problem/18110

#include <algorithm>
#include <cmath>
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

    int n, cut, temp, sum = 0;
    cin >> n;

    if (!n) {
        cout << 0;
        return 0;
    }
    cut = round((double)n * 15 / 100);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for (int i = cut; i < n - cut; i++) {
        sum += v[i];
    }

    cout << round((double)sum / (n - 2 * cut));

    return 0;
}

/*
*/